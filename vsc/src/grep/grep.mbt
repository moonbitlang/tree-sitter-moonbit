///|
fn moonbit() -> @pattern.Language!Error {
  let contexts : Map[String, @pattern.Context] = {
    "exp": @pattern.Context::new!(
      #|fn main {
      #|  $
      #|}
      ,
      strip=true,
      selector=
        #|(structure
        #| (structure_item
        #|  (function_definition
        #|   (block_expression
        #|    "{"
        #|    (statement_expression
        #|     (_) @exp)
        #|    "}"))))
      ,
    ),
    "top": @pattern.Context::new!(
      "$",
      selector=
        #|(structure_item) @top
      ,
    ),
    "pat": @pattern.Context::new!(
      #|fn main {
      #|  match x {
      #|    $ => y
      #|  }
      #|}
      ,
      selector=
        #|(pattern)
      ,
    ),
    "ty": @pattern.Context::new!(
      #|let x : $ = 42
      ,
      selector=
        #|(type)
      ,
    ),
    "case": @pattern.Context::new!(
      #|fn main {
      #|  match x {
      #|    $
      #|  }
      #|}
      ,
      selector=
        #|(case_clause) @case
      ,
    ),
    "matrix": @pattern.Context::new!(
      #|fn main {
      #|  loop a, b {
      #|    $
      #|  }
      #|}
      ,
      selector=
        #|(matrix_case_clause) @matrix
      ,
    ),
  }
  let entries : Map[String, @pattern.Entry] = {
    "exp": @pattern.Entry::new(
      name="exp",
      selector=
        #|[
        #|  (expression)
        #|  (pipeline_expression)
        #|  (compound_expression)
        #|  (match_expression)
        #|  (named_matrix_expression)
        #|  (guard_expression)
        #|  (statement_expression)
        #|  (simple_expression)
        #|] @exp
      ,
      placeholder="{...}",
    ),
    "top": @pattern.Entry::new(
      name="top",
      selector=
        #|[
        #|  (structure_item)
        #|] @top
      ,
      placeholder=
        #|type! A Int
      ,
    ),
    "pat": @pattern.Entry::new(
      name="pat",
      selector=
        #|[
        #|  (pattern)
        #|  (simple_pattern)
        #|] @pat
      ,
      placeholder="_",
    ),
    "id": @pattern.Entry::new(
      name="id",
      selector=
        #|[
        #|  (identifier)
        #|  (lowercase_identifier)
        #|  (uppercase_identifier)
        #|  (qualified_identifier)
        #|  (constructor_expression)
        #|] @id
      ,
      placeholder="id",
    ),
    "ty": @pattern.Entry::new(
      name="ty",
      selector=
        #|[
        #|  (type)
        #|  (return_type)
        #|] @ty
      ,
      placeholder="A",
    ),
  }
  let extras = ["semicolon"]
  let language = @tree_sitter_moonbit.language()
  @pattern.Language::new!(language, contexts~, entries~, extras~)
}

///|
fn jsonrpc_result[Result : ToJson](id~ : Json, result : Result) -> Unit {
  let response : Json = {
    "jsonrpc": "2.0",
    "result": result.to_json(),
    "id": id,
  }
  println(response.stringify())
}

///|
fn jsonrpc_error(id~ : Json, error : String) -> Unit {
  let response : Json = {
    "jsonrpc": "2.0",
    "error": { "code": -32603, "message": error.to_json() },
    "id": id,
  }
  println(response.stringify())
}

///|
pub fn search(
  language : @pattern.Language,
  query : String,
  content : String
) -> Iter[@pattern.Match]!Error {
  let query = language.compile!(query)
  query.search!(content)
}

///|
pub fn replace(matched : @pattern.Match, replace : String) -> @pattern.Edit! {
  matched.replace!(replace)
}

///|
extern "c" fn getchar() -> Int = "getchar"

///|
fn main {
  let buffer = @buffer.new()
  try {
    let language = moonbit!()
    fn on_submit!() {
      if buffer.is_empty() {
        return
      }
      let content = @encoding.decode!(buffer.contents(), encoding=UTF8)
      let json = @json.parse!(content)
      match json {
        {
          "id": id,
          "method": "search",
          "params": { "content": String(content), "query": String(query), .. },
          ..
        } =>
          for result in search!(language, query, content) {
            jsonrpc_result(id~, result)
          }
        {
          "id": id,
          "method": "replace",
          "params": {
            "captures": Object(captures_json),
            "replace": String(replace),
            ..
          },
          ..
        } => {
          let captures : Map[@string.View, Array[@pattern.Text]] = {}
          for name, capture_json in captures_json {
            captures[name.view()] = @json.from_json!(capture_json)
          }
          try {
            jsonrpc_result(id~, @pattern.replace!(captures, replace))
          } catch {
            error => jsonrpc_error(id~, error.to_string())
          }
        }
        { "id": id, .. } => jsonrpc_error(id~, "Invalid request")
        _ => jsonrpc_error(id=Json::null(), "Invalid request")
      }
      buffer.reset()
    }

    loop getchar() {
      '\n' => {
        try {
          on_submit!()
        } catch {
          error => jsonrpc_error(id=Json::null(), error.to_string())
        }
        continue getchar()
      }
      0..<_ as byte => {
        buffer.write_byte(byte.to_byte())
        continue getchar()
      }
      _..<0 => on_submit!()
    }
  } catch {
    error => jsonrpc_error(id=Json::null(), error.to_string())
  }
}
