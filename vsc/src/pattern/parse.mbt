///|
priv struct ByteRange {
  start : Int
  end : Int
} derive(Show, ToJson)

///|
fn ByteRange::new(start : Int, end : Int) -> ByteRange {
  ByteRange::{ start, end }
}

///|
fn ByteRange::covers(
  self : ByteRange,
  node : @tree_sitter.Node,
  offset~ : Int = 0
) -> Bool {
  node.start_byte() >= self.start + offset &&
  node.end_byte() <= self.end + offset
}

///|
fn ByteRange::covered_by(
  self : ByteRange,
  node : @tree_sitter.Node,
  offset~ : Int = 0
) -> Bool {
  node.start_byte() <= self.start + offset &&
  node.end_byte() >= self.end + offset
}

///|
fn ByteRange::intersects_with(
  self : ByteRange,
  node : @tree_sitter.Node,
  offset~ : Int = 0
) -> Bool {
  node.start_byte() < self.end + offset && node.end_byte() > self.start + offset
}

///|
type! ParseError {
  ParseError(Array[@tree_sitter.ParseError])
  QueryError(@tree_sitter.QueryError)
  UnrecognizedCharacter(ByteRange, Char)
  UnterminatedGroup(ByteRange)
  MissingColon(ByteRange)
  UnrecognizedEntry(ByteRange, String)
} derive(Show)

///|
priv enum Quote {
  Group(range~ : ByteRange, quantifier~ : Quantifier, Array[Quote])
  Match(name~ : String, range~ : ByteRange, entry~ : Entry)
} derive(Show, ToJson)

///|
fn Quote::group(
  range~ : ByteRange,
  quantifier~ : Quantifier,
  children~ : Array[Quote]
) -> Quote {
  Group(range~, quantifier~, children)
}

///|
fn Quote::range(self : Quote) -> ByteRange {
  match self {
    Group(range~, _, ..) => range
    Match(range~, ..) => range
  }
}

///|
priv enum GroupState {
  Empty(children~ : Array[Quote])
  Group(state~ : GroupState, children~ : Array[Quote], start~ : Int)
}

///|
fn GroupState::children(self : GroupState) -> Array[Quote] {
  match self {
    Empty(children~) => children
    Group(children~, ..) => children
  }
}

///|
fn GroupState::to_parse_state(self : GroupState) -> ParseState {
  match self {
    Empty(children~) => ParseState::Empty(children~)
    Group(state~, children~, start~) =>
      ParseState::Group(state~, children~, start~)
  }
}

///|
priv enum Quantifier {
  ZeroOrOne
  ZeroOrMore
  One
  OneOrMore
} derive(Show, ToJson)

///|
priv enum ParseState {
  Empty(children~ : Array[Quote])
  Group(state~ : GroupState, children~ : Array[Quote], start~ : Int)
  Entry(state~ : GroupState, buffer~ : StringBuilder)
  Match(
    state~ : GroupState,
    entry~ : Entry,
    start~ : Int,
    buffer~ : StringBuilder
  )
}

///|
struct Context {
  prefix : @string.View
  suffix : @string.View
  select : @string.View
  strip : Bool
}

///|
pub fn Context::new!(
  context : @string.View,
  strip~ : Bool = false,
  selector~ : @string.View
) -> Context!ContextError {
  let prefix = StringBuilder::new()
  loop context {
    ['$', .. context] =>
      return Context::{
        prefix: prefix.to_string(),
        suffix: context,
        strip,
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
pub impl @json.FromJson for Context with from_json(
  json : Json,
  path : @json.JsonPath
) {
  guard json is Object(dict) else {
    raise @json.JsonDecodeError((path, "Expected object"))
  }
  guard dict.get("context") is Some(String(context)) else {
    raise @json.JsonDecodeError((path, "Expect \"context\": string"))
  }
  guard dict.get("selector") is Some(String(selector)) else {
    raise @json.JsonDecodeError((path, "Expect \"selector\": string"))
  }
  guard dict.get("strip") is Some(strip) && strip.as_bool() is Some(strip) else {
    raise @json.JsonDecodeError((path, "Expect \"strip\": bool"))
  }
  try {
    Context::new!(context, strip~, selector~)
  } catch {
    error => raise @json.JsonDecodeError((path, "Invalid context: \{error}"))
  }
}

///|
struct Entry {
  name : @string.View
  selector : @string.View
  placeholder : @string.View
} derive(Show, ToJson)

///|
pub impl @json.FromJson for Entry with from_json(
  json : Json,
  path : @json.JsonPath
) {
  match json {
    {
      "name": String(name),
      "selector": String(selector),
      "placeholder": String(placeholder),
      ..
    } => return Entry::new(name~, selector~, placeholder~)
    _ => {
      let message = "Expected { \"name\": string, \"selector\": string, \"placeholder\": string }"
      raise (path, message) |> @json.JsonDecodeError
    }
  }
}

///|
pub fn Entry::new(
  name~ : @string.View,
  selector~ : @string.View,
  placeholder~ : @string.View
) -> Entry {
  Entry::{ name, selector, placeholder }
}

///|
struct Language {
  language : @tree_sitter.Language
  parser : @tree_sitter.Parser
  contexts : Map[String, Context]
  entries : Map[String, Entry]
  extras : Array[String]
  mut id : Int
}

///|
pub fn Language::language(self : Language) -> @tree_sitter.Language {
  self.language
}

///|
type! ContextError {
  MissingInterpolator
} derive(Show)

///|
pub fn Language::new(
  language : @tree_sitter.Language,
  contexts~ : Map[String, Context],
  entries~ : Map[String, Entry],
  extras~ : Array[String] = []
) -> Language! {
  let parsed_contexts = Map::new(capacity=contexts.size())
  for name, context in contexts {
    parsed_contexts.set(name, context)
  }
  let parser = @tree_sitter.Parser::new()
  parser.set_language!(language)
  Language::{
    language,
    parser,
    contexts: parsed_contexts,
    entries,
    extras,
    id: 0,
  }
}

///|
fn generate_capture(
  node~ : @tree_sitter.Node,
  name~ : String,
  buffer~ : StringBuilder,
  extras~ : Array[String]
) -> Unit {
  buffer.write_string("((")
  buffer.write_string(node.type_().to_string())
  if name != "_" {
    buffer.write_string(") @")
    buffer.write_string(name)
  } else {
    buffer.write_char(')')
  }
  let node_extras = []
  for symbol in node.next_symbol_names() {
    let symbol = symbol.to_string()
    if extras.contains(symbol) {
      node_extras.push(symbol)
    }
  }
  match node_extras {
    [] => ()
    [extra] => {
      buffer.write_char('(')
      buffer.write_string(extra)
      buffer.write_string(")")
    }
    extras => {
      buffer.write_char('[')
      for extra in extras {
        buffer.write_char('(')
        buffer.write_string(extra)
        buffer.write_char(')')
      }
      buffer.write_string("]")
    }
  }
  buffer.write_char(')')
}

///|
fn generate_captures(
  node~ : @tree_sitter.Node,
  captures~ : Array[Capture],
  buffer~ : StringBuilder,
  extras~ : Array[String]
) -> Unit {
  match captures {
    [] => abort("Empty replacement")
    [capture] => generate_capture(node~, name=capture.name, buffer~, extras~)
    captures => {
      buffer.write_char('[')
      for capture in captures {
        generate_capture(node~, name=capture.name, buffer~, extras~)
      }
      buffer.write_char(']')
    }
  }
}

///|
priv struct Capture {
  name : String
}

///|
fn Capture::new(name~ : String) -> Capture {
  Capture::{ name }
}

///|
fn generate_query_for_children(
  self : Language,
  children : Array[@tree_sitter.Node],
  quotes~ : Array[Quote],
  captures~ : Map[@tree_sitter.Node, Array[Capture]],
  annotate? : String,
  offset~ : Int,
  buffer~ : StringBuilder
) -> Unit!ParseError {
  struct Group {
    range : ByteRange
    quantifier : Quantifier
    mut closed : Bool
  } derive(Show, ToJson)

  // We use a queue to maintain the active set of quotes.
  let mut quotes_queue : @deque.T[Quote] = @deque.from_array(quotes)
  let opened_groups : Array[Group] = []
  for i, child in children {
    // BFS traversal of the quotes. Basically we are looking for all the
    // quotes that match the current child node.
    // 1. If the quote is a match.
    //    a. If its range covers the child node, we add it to the child quotes,
    //       and remove it from the queue.
    //    b. If its range does not cover the child node, we schedule it for
    //       processing later by adding it to the next queue.
    // 2. If the quote is a group.
    //    a. If its range covers the child node, we unpack the quotes inside
    //       the group and add them to the current queue so that they get
    //       processed immediately.
    //    b. If its range intersects the child node, we add it to the child
    //       quotes, and remove it from the queue.
    //    c. If its range has no intersection with the child node, we add it to
    //       the next queue so that it gets processed later.
    let child_quotes = []
    let quotes_queue_next = @deque.new()
    while quotes_queue.pop_front() is Some(quote) {
      match quote {
        Match(range~, name~, entry~) =>
          if range.covers(child, offset~) {
            let cursor = try {
              @tree_sitter.Query::new!(self.language, entry.selector)
            } catch {
              e => raise QueryError(e)
            }
            for capture in cursor.captures(child) {
              if capture.name().view() != entry.name {
                continue
              }
              match captures.get(capture.node()) {
                Some(captures) => captures.push(Capture::new(name~))
                None => captures[capture.node()] = [Capture::new(name~)]
              }
            }
          } else if range.covered_by(child, offset~) {
            child_quotes.push(quote)
          } else {
            quotes_queue_next.push_back(quote)
          }
        Group(range~, group_quotes, quantifier~) =>
          if range.covers(child, offset~) {
            buffer.write_char('(')
            opened_groups.push(Group::{ range, quantifier, closed: false })
            for group_quote in group_quotes {
              quotes_queue.push_back(group_quote)
            }
          } else if range.intersects_with(child, offset~) {
            child_quotes.push(quote)
          } else {
            quotes_queue_next.push_back(quote)
          }
      }
    }
    quotes_queue = quotes_queue_next
    if self.extras.contains(child.type_().to_string()) {
      // Handle extras. Ideally this should be done by using the next_symbols()
      // functionality provided by tree-sitter. However, it seems that it will
      // missing some of the symbols, thus we have to do it manually.
      match self.extras {
        [] => ()
        [extra] => {
          buffer.write_string("(")
          buffer.write_string(extra)
          buffer.write_string(")*")
        }
        extras => {
          buffer.write_string("[")
          for extra in extras {
            buffer.write_char('(')
            buffer.write_string(extra)
            buffer.write_char(')')
          }
          buffer.write_string("]*")
        }
      }
    } else {
      generate_query!(
        self,
        child,
        quotes=child_quotes,
        captures~,
        offset~,
        buffer~,
      )
    }
    if annotate is Some(annotate) {
      buffer.write_string("@\{annotate}")
    }
    let last = i == children.length() - 1
    for group in opened_groups {
      if not(group.closed) {
        let should_close = if not(last) {
          let next_child = children[i + 1]
          if next_child.start_byte() >= group.range.end + offset {
            true
          } else {
            false
          }
        } else {
          // Always close the group that spans beyond the last child.
          true
        }
        if should_close {
          match group.quantifier {
            ZeroOrMore => buffer.write_string(")*")
            OneOrMore => buffer.write_string(")+")
            ZeroOrOne => buffer.write_string(")?")
            One => buffer.write_string(")")
          }
          group.closed = true
        }
      }
    }
    // We emit anchor between each child node to make sure there is no extra
    // nodes between them when pattern matching.
    if not(last) {
      buffer.write_string(" . ")
    }
  }
}

///|
fn Language::id(self : Language) -> Int {
  let id = self.id
  self.id += 1
  id
}

///|
fn generate_query(
  self : Language,
  node : @tree_sitter.Node,
  quotes~ : Array[Quote],
  captures~ : Map[@tree_sitter.Node, Array[Capture]],
  offset~ : Int,
  buffer~ : StringBuilder
) -> Unit!ParseError {
  if captures.get(node) is Some(captures) {
    generate_captures(node~, captures~, buffer~, extras=self.extras)
    return
  }
  let children = node.children().collect()
  buffer.write_char('(')
  if node.is_named() {
    if children.length() == 0 {
      buffer.write_char('(')
    }
    buffer.write_string(node.type_().to_string())
    if children.length() == 0 {
      let id = "_id_\{self.id()}"
      buffer.write_string(
        ") @\{id} (#eq? @\{id} \{node.text().to_json().stringify()})",
      )
    } else {
      self.generate_query_for_children!(
        children,
        quotes~,
        captures~,
        offset~,
        buffer~,
      )
    }
  } else {
    buffer.write_string(node.type_().to_json().stringify())
    self.generate_query_for_children!(
      children,
      quotes~,
      captures~,
      offset~,
      buffer~,
    )
  }
  buffer.write_char(')')
}

///|
fn strip_colocated_nodes(node : @tree_sitter.Node) -> @tree_sitter.Node {
  for child in node.children() {
    if child.start_byte() == node.start_byte() &&
      child.end_byte() == node.end_byte() {
      return strip_colocated_nodes(child)
    }
  }
  return node
}

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
struct Query {
  parser : @tree_sitter.Parser
  query : @tree_sitter.Query
}

///|
fn Query::new(
  parser : @tree_sitter.Parser,
  query : @tree_sitter.Query
) -> Query {
  Query::{ parser, query }
}

///|
pub fn Query::search(
  self : Query,
  source : @string.View
) -> Iter[Match]!@tree_sitter.ParseError {
  let node = self.parser.parse_string!(source).root_node()
  self.matches(node)
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
      let captures = {}
      for name, capture_json in captures_json {
        match capture_json {
          Array(texts_json) => {
            let texts = []
            for text_json in texts_json {
              texts.push(@json.from_json!(text_json))
            }
            captures[name] = texts
          }
          _ => raise @json.JsonDecodeError((path, "Invalid capture"))
        }
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
struct Text {
  range : @tree_sitter.Range
  text : @string.View
}

///|
pub impl ToJson for Text with to_json(self : Text) -> Json {
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
    "text": self.text.to_json(),
  }
}

///|
pub impl @json.FromJson for Text with from_json(
  self : Json,
  path : @json.JsonPath
) -> Text!@json.JsonDecodeError {
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
      "text": String(text),
      ..
    } =>
      Text::{
        range: @tree_sitter.Range::new(
          @tree_sitter.Point::new(start_row.to_int(), start_column.to_int()),
          @tree_sitter.Point::new(end_row.to_int(), end_column.to_int()),
          start_byte.to_int(),
          end_byte.to_int(),
        ),
        text,
      }
    _ => raise @json.JsonDecodeError((path, "Invalid text"))
  }
}

///|
pub fn Query::matches(self : Query, node : @tree_sitter.Node) -> Iter[Match] {
  Iter::new(fn(yield_) {
    matches~: for matched in self.query.matches(node) {
      let query_nodes = []
      let captures : Map[String, Array[@tree_sitter.Node]] = Map::new()
      for capture in matched.captures() {
        let name = capture.name().to_string()
        let node = capture.node()
        if name.has_prefix("_query") {
          query_nodes.push(node)
        }
        match captures.get(name) {
          Some(nodes) => nodes.push(node)
          None => captures[name] = [node]
        }
      }
      for predicate in matched.predicates() {
        match predicate {
          [String("eq?"), a, b] => {
            fn read {
              @tree_sitter.String(string) => [string]
              Capture(name) =>
                match captures.get(name) {
                  None => []
                  Some(nodes) => nodes.map(fn(node) { node.text().to_string() })
                }
            }

            let a = read(a)
            let b = read(b)
            if a != b {
              continue matches~
            }
          }
          _ => ()
        }
      }
      query_nodes.sort_by(fn(a, b) { a.start_byte() - b.start_byte() })
      let query_range = @tree_sitter.Range::new(
        query_nodes[0].start_point(),
        query_nodes[query_nodes.length() - 1].end_point(),
        query_nodes[0].start_byte(),
        query_nodes[query_nodes.length() - 1].end_byte(),
      )
      let captures = captures
        .iter()
        .filter_map(fn {
          (name, nodes) => {
            guard not(name.has_prefix("_")) else { None }
            let texts = []
            for node in nodes {
              texts.push(Text::{ range: node.range(), text: node.text() })
            }
            Some((name, texts))
          }
        })
        |> Map::from_iter()
      match yield_({ range: query_range, captures }) {
        IterEnd => break matches~ IterEnd
        IterContinue => continue matches~
      }
    } else {
      IterContinue
    }
  })
}

///|
fn Language::compile_quotes(
  self : Language,
  quotes : Array[Quote],
  query : Buffer
) -> Query!ParseError {
  let parser = self.parser
  let quasi = query.to_string()
  let errors = []
  let query = StringBuilder::new()
  for name, context in self.contexts {
    let tree = try {
      parser.parse_string!("\{context.prefix}\{quasi}\{context.suffix}")
    } catch {
      e => {
        errors.push(e)
        continue
      }
    }
    if tree.root_node().has_error() {
      continue
    }
    let cursor = try {
      @tree_sitter.Query::new!(self.language, context.select)
    } catch {
      e => raise QueryError(e)
    }
    let nodes = []
    for capture in cursor.captures(tree.root_node()) {
      if capture.name() != name {
        continue
      }
      if self.extras.contains(capture.node().type_().to_string()) {
        continue
      }
      nodes.push(capture.node())
    }
    query.write_string(";; \{name}\n")
    if nodes is [] {
      self.generate_query_for_children!(
        [strip_colocated_nodes(tree.root_node())],
        quotes~,
        captures=Map::new(),
        offset=context.prefix.length(),
        buffer=query,
        annotate="_query",
      )
    } else if nodes is [node] {
      let node = if context.strip { strip_colocated_nodes(node) } else { node }
      self.generate_query_for_children!(
        [node],
        quotes~,
        captures=Map::new(),
        offset=context.prefix.length(),
        buffer=query,
        annotate="_query",
      )
    } else {
      let ancestor = lowest_common_ancestor(tree.root_node(), nodes)
      query.write_char('(')
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
      self.generate_query_for_children!(
        ancestor_children,
        quotes~,
        captures=Map::new(),
        offset=context.prefix.length(),
        buffer=query,
        annotate="_query",
      )
      query.write_char(')')
    }
    query.write_char('\n')
  }
  if errors.length() > 0 {
    raise ParseError(errors)
  }
  let query = query.to_string()
  let query = try {
    @tree_sitter.Query::new!(self.language, query)
  } catch {
    e => raise QueryError(e)
  }
  Query::new(self.parser, query)
}

///|
fn Language::parse(
  self : Language,
  source : @string.View,
  query : Buffer
) -> Array[Quote]!ParseError {
  let state = ParseState::Empty(children=[])
  loop state, 0, source {
    Empty(children~), offset, ['$', '{', .. source] =>
      continue Group(state=Empty(children~), children=[], start=query.length()),
        offset + 2,
        source
    Empty(children~), offset, ['$', .. source] =>
      continue Entry(state=Empty(children~), buffer=StringBuilder::new()),
        offset + 1,
        source
    Empty(children~), offset, [char, .. source] => {
      query.write_char(char)
      continue Empty(children~), offset + 1, source
    }
    Empty(children=quotes), _, [] => quotes
    Entry(state~, buffer~), offset, [':', char, .. source] => {
      let entry = buffer.to_string()
      buffer.reset()
      guard self.entries.get(entry) is Some(entry) else {
        raise UnrecognizedEntry(
          ByteRange::new(offset - entry.length(), offset),
          entry,
        )
      }
      match char {
        'a'..='z' | 'A'..='Z' | '_' as char => {
          let start = query.length()
          query.write_string(entry.placeholder.to_string())
          buffer.write_char(char)
          continue Match(state~, entry~, start~, buffer~), offset + 1, source
        }
        char =>
          raise UnrecognizedCharacter(ByteRange::new(offset, offset + 1), char)
      }
    }
    Entry(state~, buffer~),
    offset,
    ['a'..='z' | 'A'..='Z' | '_' | '0'..='9' as char, .. source] => {
      buffer.write_char(char)
      continue Entry(state~, buffer~), offset + 1, source
    }
    Entry(..), offset, [char, ..] =>
      raise UnrecognizedCharacter(ByteRange::new(offset, offset + 1), char)
    Entry(..), offset, [] =>
      raise MissingColon(ByteRange::new(offset, offset + 1))
    Match(state~, entry~, start~, buffer~),
    offset,
    ['a'..='z' | 'A'..='Z' | '_' | '0'..='9' as char, .. source] => {
      buffer.write_char(char)
      continue Match(state~, entry~, start~, buffer~), offset + 1, source
    }
    Match(state~, entry~, start~, buffer~), offset, [.. source] => {
      let ident = buffer.to_string()
      buffer.reset()
      state
      .children()
      .push(
        Match(
          name=ident,
          range=ByteRange::{ start, end: query.length() },
          entry~,
        ),
      )
      continue state.to_parse_state(), offset, source
    }
    Group(state~, children~, start~), offset, [.. "\\{", .. source] => {
      query.write_char('{')
      continue Group(state~, children~, start~), offset + 2, source
    }
    Group(state~, children~, start~), offset, [.. "\\}", .. source] => {
      query.write_char('}')
      continue Group(state~, children~, start~), offset + 2, source
    }
    Group(state~, children~, start~), offset, ['}', .. source] => {
      let (quantifier, offset, source) = match source {
        ['*', .. source] => (ZeroOrMore, offset + 2, source)
        ['+', .. source] => (OneOrMore, offset + 2, source)
        ['?', .. source] => (ZeroOrOne, offset + 2, source)
        [.. source] => (One, offset + 1, source)
      }
      state
      .children()
      .push(
        Group(
          range=ByteRange::{ start, end: query.length() },
          quantifier~,
          children,
        ),
      )
      continue state.to_parse_state(), offset, source
    }
    Group(state~, children~, start~), offset, ['$', '{', .. source] =>
      continue Group(
          state=Group(state~, children~, start~),
          children=[],
          start=query.length(),
        ),
        offset + 2,
        source
    Group(state~, children~, start~), offset, ['$', .. source] =>
      continue Entry(
          state=Group(state~, children~, start~),
          buffer=StringBuilder::new(),
        ),
        offset + 1,
        source
    Group(state~, children~, start~), offset, [char, .. source] => {
      query.write_char(char)
      continue Group(state~, children~, start~), offset + 1, source
    }
    Group(start~, ..), offset, [] =>
      raise UnterminatedGroup(ByteRange::new(start, offset))
  }
}

///|
pub fn Language::compile(
  self : Language,
  source : @string.View
) -> Query!ParseError {
  let query = Buffer::new()
  let quotes = self.parse!(source, query)
  self.compile_quotes!(quotes, query)
}

///|
priv enum Replace {
  Quote(String)
  Subst(String)
}

///|
fn Replace::parse_identifier(
  source : @string.View,
  buffer : StringBuilder
) -> @string.View {
  loop source {
    ['a'..='z' | 'A'..='Z' | '_' | '0'..='9' as char, .. source] => {
      buffer.write_char(char)
      continue source
    }
    source => return source
  }
}

///|
fn Replace::parse_replaces(
  source : @string.View,
  replaces : Array[Replace]
) -> Unit {
  let buffer = StringBuilder::new()
  loop source {
    ['$', .. source] => {
      if not(buffer.is_empty()) {
        replaces.push(Replace::Quote(buffer.to_string()))
        buffer.reset()
      }
      let identifier = StringBuilder::new()
      let source = Replace::parse_identifier(source, identifier)
      replaces.push(Replace::Subst(identifier.to_string()))
      continue source
    }
    ['\\', '$', .. source] => {
      buffer.write_char('$')
      continue source
    }
    [char, .. source] => {
      buffer.write_char(char)
      continue source
    }
    [] => {
      if not(buffer.is_empty()) {
        replaces.push(Replace::Quote(buffer.to_string()))
        buffer.reset()
      }
      return
    }
  }
}

///|
fn Replace::parse(string : @string.View) -> Array[Replace] {
  let replaces = []
  Replace::parse_replaces(string, replaces)
  return replaces
}

///|
struct Edit {
  range : @tree_sitter.Range
  text : @string.View
}

///|
pub impl ToJson for Edit with to_json(self : Edit) -> Json {
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
    "text": self.text.to_json(),
  }
}

///|
type! ReplaceError {
  VariableNotFound(String)
  MismatchedType(expect~ : String, actual~ : String)
} derive(Show)

///|
pub fn Match::replace(self : Match, source : @string.View) -> Edit!ReplaceError {
  let replaces = Replace::parse(source)
  let replaced = StringBuilder::new()
  for replace in replaces {
    match replace {
      Quote(string) => replaced.write_string(string)
      Subst(name) =>
        match self.captures.get(name) {
          None => raise VariableNotFound(name)
          Some([node]) => {
            let text = node.text
            for char in text {
              replaced.write_char(char)
            }
          }
          Some(_) =>
            raise MismatchedType(expect="single node", actual="multiple nodes")
        }
    }
  }
  Edit::{ range: self.range, text: replaced.to_string() }
}

///|
pub fn replace(
  captures : Map[@string.View, Array[Text]],
  replace : @string.View
) -> @string.View!ReplaceError {
  let replaces = Replace::parse(replace)
  let replaced = StringBuilder::new()
  for replace in replaces {
    match replace {
      Quote(string) => replaced.write_string(string)
      Subst(name) =>
        match captures.get(name) {
          None => raise VariableNotFound(name)
          Some([text]) =>
            for char in text.text {
              replaced.write_char(char)
            }
          Some(_) =>
            raise MismatchedType(expect="single node", actual="multiple nodes")
        }
    }
  }
  replaced.to_string()
}
