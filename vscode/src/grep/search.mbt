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
// Function using built-in equality for Node comparison
fn node_equal(this : @tree_sitter.Node, that : @tree_sitter.Node) -> Bool {
  return this == that
}

///|
// Check if two ranges overlap
fn ranges_overlap(this : @tree_sitter.Range, that : @tree_sitter.Range) -> Bool {
  return this.start_byte() < that.end_byte() && 
         this.end_byte() > that.start_byte()
}

///|
// Get corresponding AST node based on byte range
fn get_node_at_range(root_node : @tree_sitter.Node, range : @tree_sitter.Range) -> Option[@tree_sitter.Node] {
  return root_node.descendant_for_byte_range(
    range.start_byte(),
    range.end_byte()
  )
}



///|
// Deduplication based on AST node member consistency using built-in equality
fn match_equal_by_ast(this : Match, that : Match, root_node : @tree_sitter.Node) -> Bool {
      // First check if ranges overlap
  if not(ranges_overlap(this.range, that.range)) {
    return false
  }
  
      // Get AST nodes corresponding to two matches
  let this_node_opt = get_node_at_range(root_node, this.range)
  let that_node_opt = get_node_at_range(root_node, that.range)
  
      // If unable to get nodes, fallback to range deduplication
  if this_node_opt == None || that_node_opt == None {
    return ranges_overlap(this.range, that.range)
  }
  
  let this_node = this_node_opt.unwrap()
  let that_node = that_node_opt.unwrap()
  
      // Use built-in equality for Node comparison
  return this_node == that_node
}

///|
// AST-based deduplication function using built-in equality
fn deduplicate_by_ast(matches : Array[Match], root_node : @tree_sitter.Node) -> Array[Match] {
  if matches.length() <= 1 {
    return matches
  }
  
  let unique_matches : Array[Match] = []
  let processed_indices : Array[Int] = []
  
  for i = 0; i < matches.length(); i = i + 1 {
    let mut is_duplicate = false
    
    // Compare with already processed results using built-in equality
    for j = 0; j < processed_indices.length(); j = j + 1 {
      let processed_match = matches[processed_indices[j]]
      
      // Use match_equal_by_ast for comparison
      if match_equal_by_ast(matches[i], processed_match, root_node) {
        is_duplicate = true
        break
      }
    }
    
    if not(is_duplicate) {
      unique_matches.push(matches[i])
      processed_indices.push(i)
    }
  }
  
  return unique_matches
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
    // Reuse precompiled query: execute matching on specified Node
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
// Cascading search: each layer searches within the result range of the previous layer
// Precise search based on node ranges, avoiding full file scanning
// 
// Parameters:
//   content - file content to search
//   main_query - main query string
//   layer_queries - array of layer query strings
// 
// Returns: iterator of match results
pub fn cascade_search(
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
  
      // Execute main query to get initial result set
  let main_results = search(query=main_query, content=content) catch {
    _ => {
      return Iter::empty()
    }
  }
  
  let main_results_array = main_results.collect()
  
      // Boundary condition: return directly when main query has no results
  if main_results_array.length() == 0 {
    return Iter::empty()
  }
  
      // Boundary condition: return main query results when no layer queries (using AST deduplication)
  if layer_queries.length() == 0 {
    let deduplicated_main_results = deduplicate_by_ast(main_results_array, root_node)
    return Iter::new(fn(yield_) {
      for result in deduplicated_main_results {
        match yield_(result) {
          IterEnd => break
          IterContinue => continue
        }
      }
      IterContinue
    })
  }
  
      // Precompile all layer queries to improve performance
  let compiled_layer_queries : Array[@tree_sitter.Query] = []
  for layer_query in layer_queries {
    if layer_query == "" { continue }
    let q = compiler.compile(layer_query) catch {
      _ => { continue }
    }
    compiled_layer_queries.push(q)
  }
  
      // Boundary condition: return empty results when no valid layer queries
  if compiled_layer_queries.length() == 0 {
    return Iter::empty()
  }
  
      // Core logic of cascading search: search layer by layer within result ranges
  let mut current_results = main_results_array
  let mut current_level = 0
  
  for layer_query in compiled_layer_queries {
    current_level = current_level + 1
    
          // Prepare result container for current layer
    let next_level_results = []
    
    for current_result in current_results {
      // Locate corresponding AST node based on byte range
      let current_node = root_node.descendant_for_byte_range(
        current_result.range.start_byte(),
        current_result.range.end_byte()
      )
      
      match current_node {
        Some(node) => {
          // Execute layer query within limited node range
          let layer_matches = search_in_node_with_query(query=layer_query, node=node)
          let layer_results = layer_matches.collect()
          
                      // Collect match results for current layer
          for layer_result in layer_results {
            next_level_results.push(layer_result)
          }
        }
                  None => {
            // Skip current result when node location fails
          continue
        }
      }
    }
    
          // Perform AST deduplication on current layer results
    current_results = deduplicate_by_ast(next_level_results, root_node)
    
          // Optimization: terminate search early when current layer has no results
    if current_results.length() == 0 {
      return Iter::empty()
    }
  }
  
      // Perform AST deduplication on final results
  let deduplicated_results = deduplicate_by_ast(current_results, root_node)
  
      // Return deduplicated result set
  Iter::new(fn(yield_) {
    for result in deduplicated_results {
      match yield_(result) {
        IterEnd => break
        IterContinue => continue
      }
    }
    IterContinue
  })
}


