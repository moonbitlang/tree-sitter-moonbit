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
        start_byte = @math.minimum(start_byte, parent.start_byte())
        end_byte = @math.maximum(end_byte, parent.end_byte())
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
      #|fn main {
      #|  $
      #|}
      ,
      selector=
        #|(structure
        #| (function_definition
        #|  (block_expression
        #|   "{"
        #|   (_) @exp
        #|   "}")))
      ,
    ),
    "top": Context::new(
      "$",
      selector=
        #|(structure
        #| (_) @top)
      ,
    ),
    "pat": Context::new(
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
    "ty": Context::new(
      #|let x : $ = 42
      ,
      selector=
        #|(type)
      ,
    ),
    "case": Context::new(
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
    "matrix": Context::new(
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
          "row": Number(start_row),
          "column": Number(start_column),
          "byte": Number(start_byte),
          ..
        },
        "end": {
          "row": Number(end_row),
          "column": Number(end_column),
          "byte": Number(end_byte),
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
    e => raise ParseError(e)
  }
  let query = compiler.compile(query)
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
        .filter_map(fn {
          (['_', ..], _) => None
          (name, nodes) => {
            let text_nodes = nodes.map(fn(node) {
              Text::{ range: node.range(), text: node.text() }
            })
            Some((name, text_nodes))
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
