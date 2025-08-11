///|
struct Context {
  prefix : @string.View
  suffix : @string.View
  select : @string.View
}

///|
fn Context::new(
  context : @string.View,
  selector~ : @string.View
) -> Context raise ParseError {
  let prefix = StringBuilder::new()
  loop context {
    ['$', .. context] =>
      return Context::{
        prefix: prefix.to_string(),
        suffix: context,
        select: selector,
      }
    [.. "\\$", .. context] => {
      prefix.write_char('$')
      continue context
    }
    [char, .. context] => {
      prefix.write_char(char)
      continue context
    }
    [] => raise MissingInterpolator
  }
}



///|
suberror ParseError {
  MissingInterpolator
  LanguageError(@tree_sitter.LanguageError)
  ParseError(@tree_sitter.ParseError)
  SyntaxError(@tree_sitter.Node)
  QueryError(@tree_sitter.QueryError)
  Errors(Array[ParseError])
} derive(Show, ToJson)

///|
fn lowest_common_ancestor(
  root : @tree_sitter.Node,
  nodes : Array[@tree_sitter.Node]
) -> @tree_sitter.Node {
  let mut ancestor : @tree_sitter.Node? = None
  for node in nodes {
    let node_ancestor = root.child_with_descendant(node)
    match (ancestor, node_ancestor) {
      (Some(ancestor), Some(node_ancestor)) =>
        if ancestor != node_ancestor {
          return root
        }
      (None, Some(_)) => ancestor = node_ancestor
      (_, None) => continue
    }
  }
  match ancestor {
    None => root
    Some(ancestor) => lowest_common_ancestor(ancestor, nodes)
  }
}

///|
fn Compiler::compile(
  self : Compiler,
  query : @string.View
) -> @tree_sitter.Query raise ParseError {
  self.parser.set_language(self.language) catch {
    e => raise LanguageError(e)
  }
  let buffer = StringBuilder::new()
  let errors = []
  for name, context in self.contexts {
    let tree = self.parser.parse_string(
      "\{context.prefix}\{query}\{context.suffix}",
    ) catch {
      e => {
        errors.push(ParseError(e))
        continue
      }
    }
    if tree.root_node().has_error() {
      errors.push(SyntaxError(tree.root_node()))
      continue
    }
    let cursor = @tree_sitter.Query::new(self.language, context.select) catch {
      e => raise QueryError(e)
    }
    let nodes = []
    for capture in cursor.captures(tree.root_node()) {
      if capture.name().view() != name {
        continue
      }
      nodes.push(capture.node())
    }
    buffer.write_string(";; \{name}\n")
    if nodes is [] {
      self.node(tree.root_node(), path=[], buffer~)
    } else if nodes is [node] {
      self.node(node, path=[], buffer~)
    } else {
      let ancestor = lowest_common_ancestor(tree.root_node(), nodes)
      buffer.write_char('(')
      let mut start_byte = ancestor.end_byte()
      let mut end_byte = ancestor.start_byte()
      for node in nodes {
        guard ancestor.child_with_descendant(node) is Some(parent) else {
          continue
        }
        start_byte = @cmp.minimum(start_byte, parent.start_byte())
        end_byte = @cmp.maximum(end_byte, parent.end_byte())
      }
      let ancestor_children = ancestor
        .children()
        .filter(fn(node) {
          node.start_byte() >= start_byte && node.end_byte() <= end_byte
        })
        .collect()
      self.nodes(ancestor_children, path=[], buffer~)
      buffer.write_char(')')
    }
    buffer.write_char('\n')
  }
  let query = buffer.to_string()
  if query == "" && errors.length() > 0 {
    raise Errors(errors)
  }
  let query = @tree_sitter.Query::new(self.language, query) catch {
    e => raise QueryError(e)
  }
  query
}

///|
priv struct Compiler {
  language : @tree_sitter.Language
  parser : @tree_sitter.Parser
  mut id : Int
  contexts : Map[@string.View, Context]
}

///|
let global_compiler : Ref[Compiler?] = Ref::new(None)

///|
fn compiler() -> Compiler raise ParseError {
  if global_compiler.val is Some(compiler) {
    return compiler
  }
  let language = @tree_sitter_moonbit.language()
  let contexts : Map[@string.View, Context] = {
    "exp": Context::new(
      (
        #|fn main {
        #|  $
        #|}
      ),
      selector=(
        #|(structure
        #| (function_definition
        #|  (block_expression
        #|   "{"
        #|   (_) @exp
        #|   "}")))
      ),
    ),
    "top": Context::new(
      "$",
      selector=(
        #|(structure
        #| (_) @top)
      ),
    ),
    "pat": Context::new(
      (
        #|fn main {
        #|  match x {
        #|    $ => y
        #|  }
        #|}
      ),
      selector=(
        #|(pattern)
      ),
    ),
    "ty": Context::new(
      (
        #|let x : $ = 42
      ),
      selector=(
        #|(type)
      ),
    ),
    "case": Context::new(
      (
        #|fn main {
        #|  match x {
        #|    $
        #|  }
        #|}
      ),
      selector=(
        #|(case_clause) @case
      ),
    ),
    "matrix": Context::new(
      (
        #|fn main {
        #|  loop a, b {
        #|    $
        #|  }
        #|}
      ),
      selector=(
        #|(matrix_case_clause) @matrix
      ),
    ),
  }
  let parser = @tree_sitter.Parser::new()
  parser.set_language(language) catch {
    e => raise LanguageError(e)
  }
  let compiler = Compiler::{ language, parser, id: 0, contexts }
  global_compiler.val = Some(compiler)
  return compiler
}

///|
fn Compiler::id(self : Compiler) -> Int {
  let id = self.id
  self.id += 1
  id
}

///|
fn Compiler::nodes(
  self : Compiler,
  nodes : Array[@tree_sitter.Node],
  path~ : Array[Int],
  buffer~ : StringBuilder
) -> Unit raise ParseError {
  for i, node in nodes {
    self.node(node, path=[..path, i], buffer~)
    if i < nodes.length() - 1 {
      buffer.write_string(" . ")
    }
  }
}

///|
fn Compiler::node(
  self : Compiler,
  node : @tree_sitter.Node,
  path~ : Array[Int],
  buffer~ : StringBuilder
) -> Unit raise ParseError {
  let children = node.children().collect()
  buffer.write_char('(')
  if node.is_named() {
    // If the node has no children, we assume it is a terminal node and we
    // check for string equality.
    let type_ = node.type_().to_string()
    if type_ is [.., .. "_identifier"] &&
      children is [child] &&
      child.type_() is [.. "quotation_", .., .. "_identifier_expander"] {
      buffer.write_char('(')
    } else if children.length() == 0 {
      buffer.write_char('(')
    }
    if type_ is [.. "quotation_", .., .. "_expander"] {
      let mut name = None
      for child in children {
        if child.type_() == "quotation_variable" {
          if name is None {
            name = Some(child.text().to_string())
          }
        }
      }
      guard name is Some(name)
      buffer.write_string("(_) @\{name}")
    } else {
      buffer.write_string(type_)
      if type_ is [.., .. "_identifier"] &&
        children is [child] &&
        child.type_() is [.. "quotation_", .., .. "_identifier_expander"] {
        let mut name = None
        for grandchild in child.children() {
          if grandchild.type_() == "quotation_variable" {
            name = Some(grandchild.text().to_string())
            break
          }
        }
        if name is Some(name) {
          buffer.write_string(") @\{name}")
        } else {
          buffer.write_char(')')
        }
      } else if children.length() == 0 {
        let id = "_terminal_\{self.id()}"
        buffer.write_string(
          ") @\{id} (#eq? @\{id} \{node.text().to_json().stringify()})",
        )
      } else {
        self.nodes(children, path~, buffer~)
      }
    }
  } else if node.type_() == "$..." {
    buffer.write_string("(_)*")
  } else {
    buffer.write_string(node.type_().to_json().stringify())
    self.nodes(children, path~, buffer~)
  }
  let path = ["_", ..path.map(fn(i) { i.to_string() })].join(".")
  buffer.write_string(") @\{path}")
}

///|
struct Match {
  range : @tree_sitter.Range
  captures : Map[String, Array[Text]]
}

///|
pub impl ToJson for Match with to_json(self : Match) -> Json {
  {
    "range": {
      "start": {
        "row": self.range.start_point().row().to_json(),
        "column": self.range.start_point().column().to_json(),
        "byte": self.range.start_byte().to_json(),
      },
      "end": {
        "row": self.range.end_point().row().to_json(),
        "column": self.range.end_point().column().to_json(),
        "byte": self.range.end_byte().to_json(),
      },
    },
    "captures": self.captures.to_json(),
  }
}

///|
pub impl @json.FromJson for Match with from_json(
  self : Json,
  path : @json.JsonPath
) -> Match raise @json.JsonDecodeError {
  match self {
    {
      "range": {
        "start": {
          "row": Number(start_row, ..),
          "column": Number(start_column, ..),
          "byte": Number(start_byte, ..),
          ..
        },
        "end": {
          "row": Number(end_row, ..),
          "column": Number(end_column, ..),
          "byte": Number(end_byte, ..),
          ..
        },
        ..
      },
      "captures": captures_json,
      ..
    } => {
      let captures : Map[String, Array[Text]] = @json.from_json(
        captures_json,
        path=path.add_key("captures"),
      )
      Match::{
        range: @tree_sitter.Range::new(
          @tree_sitter.Point::new(start_row.to_int(), start_column.to_int()),
          @tree_sitter.Point::new(end_row.to_int(), end_column.to_int()),
          start_byte.to_int(),
          end_byte.to_int(),
        ),
        captures,
      }
    }
    _ => raise @json.JsonDecodeError((path, "Invalid match"))
  }
}

///|
fn node_equal(this : @tree_sitter.Node, that : @tree_sitter.Node) -> Bool {
  if this.is_named() != that.is_named() {
    return false
  }
  if this.type_() != that.type_() {
    return false
  }
  let this_children = this.children().collect()
  let that_children = that.children().collect()
  if this_children.length() != that_children.length() {
    return false
  }
  for i = 0; i < this_children.length(); i = i + 1 {
    let this_child = this_children[i]
    let that_child = that_children[i]
    if not(node_equal(this_child, that_child)) {
      return false
    }
  }
  return true
}

///|
fn search(
  query~ : @string.View,
  content~ : @string.View
) -> Iter[Match] raise ParseError {
  let compiler = compiler()
  let root_node = compiler.parser.parse_string(content).root_node() catch {
    e => { raise ParseError(e) }
  }
  
  let query = compiler.compile(query) catch { _ => { return Iter::empty() } }
  
  Iter::new(fn(yield_) {
    matches~: for matched in query.matches(root_node) {
      let nodes = []
      let captures : Map[String, Array[@tree_sitter.Node]] = {}
      for capture in matched.captures() {
        let name = capture.name()
        let node = capture.node()
        nodes.push(node)
        match captures.get(name) {
          Some([repr, ..]) =>
            if not(node_equal(repr, node)) {
              continue matches~
            }
          Some([] as nodes) => nodes.push(node)
          _ => captures[name] = [node]
        }
      }
      for predicate in matched.predicates() {
        match predicate {
          [String("eq?"), Capture(this), Capture(that)] =>
            match (captures.get(this), captures.get(that)) {
              (Some([this_node, ..]), Some([that_node, ..])) =>
                if not(node_equal(this_node, that_node)) {
                  continue matches~
                }
              (Some([]), Some([])) | (None, None) => ()
              _ => continue matches~
            }
          [String("eq?"), String(string), Capture(name)]
          | [String("eq?"), Capture(name), String(string)] =>
            match captures.get(name) {
              Some([node, ..]) => if node.text() != string { continue matches~ }
              Some([]) | None => continue matches~
            }
          [String("eq?"), String(this), String(that)] =>
            if this != that {
              continue matches~
            }
          _ => ()
        }
      }
      let captures = captures
        .iter()
        .filter_map(fn(name_nodes) {
          match name_nodes {
            (['_', ..], _) => None
            (name, nodes) => {
              let text_nodes = nodes.map(fn(node) {
                Text::{ range: node.range(), text: node.text() }
              })
              Some((name, text_nodes))
            }
          }
        })
        |> Map::from_iter()
      nodes.sort_by(fn(a, b) { a.start_byte() - b.start_byte() })
      let start_point = nodes[0].start_point()
      let start_byte = nodes[0].start_byte()
      let end_point = nodes[nodes.length() - 1].end_point()
      let end_byte = nodes[nodes.length() - 1].end_byte()
      let range = @tree_sitter.Range::new(
        start_point, end_point, start_byte, end_byte,
      )
      match yield_(Match::{ range, captures }) {
        IterEnd => break IterEnd
        IterContinue => continue
      }
    } else {
      IterContinue
    }
  })
}
 
///|
// 复用预编译查询：在指定 Node 上执行匹配
fn search_in_node_with_query(
  query~ : @tree_sitter.Query,
  node~ : @tree_sitter.Node,
) -> Iter[Match] {
  Iter::new(fn(yield_) {
    matches~: for matched in query.matches(node) {
      let nodes = []
      let captures : Map[String, Array[@tree_sitter.Node]] = {}
      for capture in matched.captures() {
        let name = capture.name()
        let node = capture.node()
        nodes.push(node)
        match captures.get(name) {
          Some([repr, ..]) =>
            if not(node_equal(repr, node)) {
              continue matches~
            }
          Some([] as nodes) => nodes.push(node)
          _ => captures[name] = [node]
        }
      }
      for predicate in matched.predicates() {
        match predicate {
          [String("eq?"), Capture(this), Capture(that)] =>
            match (captures.get(this), captures.get(that)) {
              (Some([this_node, ..]), Some([that_node, ..])) =>
                if not(node_equal(this_node, that_node)) {
                  continue matches~
                }
              (Some([]), Some([])) | (None, None) => ()
              _ => continue matches~
            }
          [String("eq?"), String(string), Capture(name)]
          | [String("eq?"), Capture(name), String(string)] =>
            match captures.get(name) {
              Some([node, ..]) => if node.text() != string { continue matches~ }
              Some([]) | None => continue matches~
            }
          [String("eq?"), String(this), String(that)] =>
            if this != that {
              continue matches~
            }
          _ => ()
        }
      }
      let captures = captures
        .iter()
        .filter_map(fn(name_nodes) {
          match name_nodes {
            (['_', ..], _) => None
            (name, nodes) => {
              let text_nodes = nodes.map(fn(node) {
                Text::{ range: node.range(), text: node.text() }
              })
              Some((name, text_nodes))
            }
          }
        })
        |> Map::from_iter()
      nodes.sort_by(fn(a, b) { a.start_byte() - b.start_byte() })
      let start_point = nodes[0].start_point()
      let start_byte = nodes[0].start_byte()
      let end_point = nodes[nodes.length() - 1].end_point()
      let end_byte = nodes[nodes.length() - 1].end_byte()
      let range = @tree_sitter.Range::new(
        start_point, end_point, start_byte, end_byte,
      )
      
      // 调试：显示匹配的详细信息
      let match_text = nodes[0].text()
      let match_type = nodes[0].type_()
      // 注意：这里我们无法访问 id，所以暂时注释掉调试输出
      // jsonrpc_result("DEBUG: Match found: type=\{match_type}, text='\{match_text}', bytes=\{start_byte}-\{end_byte}")
      
      match yield_(Match::{ range, captures }) {
        IterEnd => break IterEnd
        IterContinue => continue
      }
    } else {
      IterContinue
    }
  })
}
 
///|
// 基于Node的嵌套多层搜索
pub fn nested_node_search(
  content~ : @string.View,
  main_query~ : @string.View,
  layer_queries : Array[@string.View]
) -> Iter[Match] raise ParseError {
  let compiler = compiler()
  let root_node = compiler.parser.parse_string(content).root_node() catch {
    _ => {
      return Iter::empty()
    }
  }
  
  let main_results = search(query=main_query, content=content) catch {
    _ => {
      return Iter::empty()
    }
  }
  
  let main_results_array = main_results.collect()
  
  if main_results_array.length() == 0 {
    return Iter::empty()
  }
  
  // 预编译所有层查询，失败的跳过
  let compiled_layer_queries : Array[@tree_sitter.Query] = []
  for layer_query in layer_queries {
    if layer_query == "" { continue }
    let q = compiler.compile(layer_query) catch {
      _ => { continue }
    }
    compiled_layer_queries.push(q)
  }
  if compiled_layer_queries.length() == 0 {
    return Iter::empty()
  }

  if layer_queries.length() == 0 {
    return Iter::new(fn(yield_) {
      for result in main_results_array {
        match yield_(result) {
          IterEnd => break
          IterContinue => continue
        }
      }
      IterContinue
    })
  }
  
  let all_layer_results = []
  
  // 调试：显示主查询结果信息
  // 注意：这里我们无法访问 id，所以暂时注释掉调试输出
  // jsonrpc_result("DEBUG: Main query found \{main_results_array.length()} results")
  
  let mut i = 0
  for main_result in main_results_array {
    let main_node = root_node.descendant_for_byte_range(
      main_result.range.start_byte(),
      main_result.range.end_byte()
    )
    
    match main_node {
      Some(node) => {
        // 调试：显示主节点的详细信息
        let node_text = node.text()
        let node_type = node.type_()
        // jsonrpc_result("DEBUG: Main result \{i}: type=\{node_type}, text='\{node_text}', bytes=\{main_result.range.start_byte()}-\{main_result.range.end_byte()}")
        
        let mut j = 0
        for q in compiled_layer_queries {
          let layer_matches = search_in_node_with_query(query=q, node=node)
          
          let layer_results = layer_matches.collect()
          
          // 调试：显示层查询结果信息
          // jsonrpc_result("DEBUG: Layer query \{j} found \{layer_results.length()} results in main result \{i}")
          
          let mut k = 0
          for layer_result in layer_results {
            // 调试：显示每个层结果的详细信息
            let layer_node = root_node.descendant_for_byte_range(
              layer_result.range.start_byte(),
              layer_result.range.end_byte()
            )
            match layer_node {
              Some(layer_node) => {
                let layer_text = layer_node.text()
                let layer_type = layer_node.type_()
                // jsonrpc_result("DEBUG: Layer result \{k}: type=\{layer_type}, text='\{layer_text}', bytes=\{layer_result.range.start_byte()}-\{layer_result.range.end_byte()}")
              }
              None => {
                // jsonrpc_result("DEBUG: Layer result \{k}: could not find node for bytes \{layer_result.range.start_byte()}-\{layer_result.range.end_byte()}")
                ignore(())
              }
            }
            
            all_layer_results.push(layer_result)
            k = k + 1
          }
          j = j + 1
        }
      }
      None => {
        // 忽略无法找到Node的结果
        // jsonrpc_result("DEBUG: Could not find node for main result \{i} at bytes \{main_result.range.start_byte()}-\{main_result.range.end_byte()}")
        ignore(())
      }
    }
    i = i + 1
  }
  
  // jsonrpc_result("DEBUG: Total layer results: \{all_layer_results.length()}")
  
  Iter::new(fn(yield_) {
    for result in all_layer_results {
      match yield_(result) {
        IterEnd => break
        IterContinue => continue
      }
    }
    IterContinue
  })
}


