///|
struct Context {
  prefix : @string.View
  suffix : @string.View
  select : @string.View
}

///|
fn Context::new!(
  context : @string.View,
  selector~ : @string.View
) -> Context!ParseError {
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
type! ParseError {
  MissingInterpolator
  ParseError(Array[@tree_sitter.ParseError])
  QueryError(@tree_sitter.QueryError)
} derive(Show)

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
) -> @tree_sitter.Query! {
  self.parser.set_language!(self.language)
  let buffer = StringBuilder::new()
  let errors = []
  for name, context in self.contexts {
    let tree = try
      self.parser.parse_string!("\{context.prefix}\{query}\{context.suffix}") catch {
      e => {
        errors.push(e)
        continue
      }
    }
    if tree.root_node().has_error() {
      continue
    }
    let cursor = try @tree_sitter.Query::new!(self.language, context.select) catch {
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
  if errors.length() > 0 {
    raise ParseError(errors)
  }
  let query = buffer.to_string()
  let query = try @tree_sitter.Query::new!(self.language, query) catch {
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
fn compiler() -> Compiler! {
  if global_compiler.val is Some(compiler) {
    return compiler
  }
  let language = @tree_sitter_moonbit.language()
  let contexts : Map[@string.View, Context] = {
    "exp": Context::new!(
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
    "top": Context::new!(
      "$",
      selector=
        #|(_) @top
      ,
    ),
    "pat": Context::new!(
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
    "ty": Context::new!(
      #|let x : $ = 42
      ,
      selector=
        #|(type)
      ,
    ),
    "case": Context::new!(
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
    "matrix": Context::new!(
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
  parser.set_language!(language)
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
) -> Unit! {
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
) -> Unit! {
  let children = node.children().collect()
  buffer.write_char('(')
  if node.is_named() {
    // If the node has no children, we assume it is a terminal node and we
    // check for string equality.
    if children.length() == 0 {
      buffer.write_char('(')
    }
    let type_ = node.type_().to_string()
    if type_.has_prefix("quotation") && type_.has_suffix("expander") {
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
      if children.length() == 0 {
        let id = "_terminal_\{self.id()}"
        buffer.write_string(
          ") @\{id} (#eq? @\{id} \{node.text().to_json().stringify()})",
        )
      } else {
        self.nodes!(children, path~, buffer~)
      }
    }
  } else if node.type_() == "$..." {
    buffer.write_string("(_)*")
  } else {
    buffer.write_string(node.type_().to_json().stringify())
    self.nodes!(children, path~, buffer~)
  }
  let path = ["_", ..path.map(fn(i) { i.to_string() })].join(".")
  buffer.write_string(") @\{path}")
}

///|
struct Match {
  range : @tree_sitter.Range
  captures : Map[@string.View, Text]
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
) -> Match!@json.JsonDecodeError {
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
      "captures": Object(captures_json),
      ..
    } => {
      let captures : Map[@string.View, Text] = {}
      for name, text_json in captures_json {
        captures[name] = @json.from_json!(text_json)
      }
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
fn search(query~ : @string.View, content~ : @string.View) -> Iter[Match]! {
  let compiler = compiler!()
  let root_node = compiler.parser.parse_string!(content).root_node()
  let query = compiler.compile!(query)
  Iter::new(fn(yield_) {
    matches~: for matched in query.matches(root_node) {
      let nodes = []
      let captures : Map[@string.View, Text] = {}
      for capture in matched.captures() {
        let name = capture.name()
        let node = capture.node()
        nodes.push(node)
        if not(name.has_prefix("_")) {
          match captures.get(name) {
            Some(text) => if text.text != node.text() { continue matches~ }
            _ =>
              captures[name] = Text::{ range: node.range(), text: node.text() }
          }
        }
      }
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
