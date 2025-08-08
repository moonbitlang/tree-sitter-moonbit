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
// 新增：多层搜索结构
struct SearchLayer {
  query : String
  enabled : Bool
}

///|
// 新增：多层搜索选项
struct MultiLayerOptions {
  main_query : String
  layers : Array[SearchLayer]
}



///|
// 新增：级联搜索主函数
pub fn cascade_search(
  content~ : @string.View,
  options~ : MultiLayerOptions
) -> Iter[Match] {
  // 首先执行主查询
  let main_results = search(query=options.main_query, content=content, debug_id=Json::null()) catch {
    _ => return Iter::empty()
  }
  
  let main_results_array = main_results.collect()
  
  if main_results_array.length() == 0 {
    return Iter::empty()
  }
  
  // 如果没有层查询，直接返回主查询结果
  if options.layers.length() == 0 {
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
  
  // 执行级联搜索：每个层都在前一层的结果范围内搜索
  let mut current_results = main_results_array
  
  for layer in options.layers {
    if not(layer.enabled) || layer.query == "" {
      continue
    }
    
    // 在当前结果范围内执行层查询
    let layer_results = Iter::new(fn(yield_) {
      for result in current_results {
        // 提取当前结果范围内的内容
        let start_line = result.range.start_point().row()
        let start_byte = result.range.start_byte()
        let end_byte = result.range.end_byte()
        
        // 从原始内容中提取该范围的内容
        let range_content = extract_content_range(content, start_byte, end_byte)
        
        // 在该范围内执行层查询
        let layer_matches = search(query=layer.query, content=range_content, debug_id=Json::null()) catch {
          _ => continue
        }
        
        for match_result in layer_matches {
          // 调整结果范围到原始文件坐标
          let adjusted_result = adjust_result_range(match_result, start_line, start_byte)
          match yield_(adjusted_result) {
            IterEnd => break
            IterContinue => continue
          }
        }
      }
      IterContinue
    }).collect()
    
    current_results = layer_results
  }
  
  Iter::new(fn(yield_) {
    for result in current_results {
      match yield_(result) {
        IterEnd => break
        IterContinue => continue
      }
    }
    IterContinue
  })
}

///|
// 新增：从内容中提取指定字节范围的内容
fn extract_content_range(content : @string.View, start_byte : Int, end_byte : Int) -> @string.View {
  if start_byte < 0 || end_byte < start_byte || start_byte >= content.length() {
    return ""
  }
  
  let actual_end_byte = @cmp.minimum(end_byte, content.length())
  
  // 使用字符级别的字符串操作，但确保字节范围正确
  let content_str = content.to_string()
  
  // 对于UTF-8字符串，我们需要小心处理字节范围
  // 这里我们使用一个简化的方法：直接使用substring，但确保范围有效
  if start_byte >= content_str.length() {
    return ""
  }
  
  let actual_end = @cmp.minimum(actual_end_byte, content_str.length())
  let result = content_str.substring(start=start_byte, end=actual_end)
  result.view()
}

///|
// 新增：检查两个范围是否重叠
fn ranges_overlap(range1 : @tree_sitter.Range, range2 : @tree_sitter.Range) -> Bool {
  // 检查字节范围是否重叠
  let start1 = range1.start_byte()
  let end1 = range1.end_byte()
  let start2 = range2.start_byte()
  let end2 = range2.end_byte()
  
  // 两个范围重叠的条件：start1 < end2 且 start2 < end1
  start1 < end2 && start2 < end1
}

// 新增：调整结果范围到原始文件坐标
fn adjust_result_range(result : Match, offset_line : Int, offset_byte : Int) -> Match {
  // 获取原始结果的范围
  let original_range = result.range
  let original_start_point = original_range.start_point()
  let original_end_point = original_range.end_point()
  
  // 调整行号和字节偏移
  let adjusted_start_point = @tree_sitter.Point::new(
    offset_line + original_start_point.row(),
    original_start_point.column()
  )
  let adjusted_end_point = @tree_sitter.Point::new(
    offset_line + original_end_point.row(),
    original_end_point.column()
  )
  
  // 创建调整后的范围
  let adjusted_range = @tree_sitter.Range::new(
    adjusted_start_point,
    adjusted_end_point,
    offset_byte + original_range.start_byte(),
    offset_byte + original_range.end_byte()
  )
  
  // 返回调整后的结果
  Match::{
    range: adjusted_range,
    captures: result.captures
  }
}



///|
// 新增：多层搜索接口
pub fn multi_layer_search(
  content~ : @string.View,
  main_query~ : @string.View,
  layer_queries : Array[@string.View],
  id~ : Json
) -> Iter[Match] {
  // 首先执行主查询
  let main_results = search(query=main_query, content=content, debug_id=id) catch {
    _ => {
      // jsonrpc_result(id=Json::null(), "DEBUG: Main query failed")
      return Iter::empty()
    }
  }
  
  let main_results_array = main_results.collect()
  
  // 临时启用调试信息来查看主查询结果
  jsonrpc_result(id=id, "DEBUG: Main query completed with \{main_results_array.length()} results")
  
  // 打印前几个主查询结果的详细信息
  let mut index = 0
  for result in main_results_array {
    if index < 3 {  // 只打印前3个结果
      let start_line = result.range.start_point().row()
      let end_line = result.range.end_point().row()
      let start_col = result.range.start_point().column()
      let end_col = result.range.end_point().column()
      jsonrpc_result(id=id, "DEBUG: Main result \{index}: lines \{start_line}-\{end_line}, cols \{start_col}-\{end_col}")
    }
    index = index + 1
  }
  
  if main_results_array.length() == 0 {
    jsonrpc_result(id=id, "DEBUG: No main results found")
    return Iter::empty()
  }
  
  // 如果没有层查询，直接返回主查询结果
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
  
  // 执行级联搜索：层查询在整个内容中查找，但只返回与主查询结果重叠的匹配
  let mut current_results = main_results_array
  
  for layer_query in layer_queries {
    if layer_query == "" {
      continue
    }
    
    // 在整个内容中执行层查询
    jsonrpc_result(id=id, "DEBUG: Executing layer query: \{layer_query}")
    jsonrpc_result(id=id, "DEBUG: Content length: \{content.length()}")
    
    let layer_matches = search(query=layer_query, content=content, debug_id=id) catch {
      e => {
        jsonrpc_result(id=id, "DEBUG: Layer query failed: \{e}")
        continue
      }
    }
    
    let layer_results_array = layer_matches.collect()
    jsonrpc_result(id=id, "DEBUG: Layer query found \{layer_results_array.length()} total matches")
    
    // 打印前几个层查询结果的详细信息
    let mut layer_index = 0
    for layer_result in layer_results_array {
      if layer_index < 5 {  // 只打印前5个结果
        let start_line = layer_result.range.start_point().row()
        let end_line = layer_result.range.end_point().row()
        let start_col = layer_result.range.start_point().column()
        let end_col = layer_result.range.end_point().column()
        jsonrpc_result(id=id, "DEBUG: Layer result \{layer_index}: lines \{start_line}-\{end_line}, cols \{start_col}-\{end_col}")
      }
      layer_index = layer_index + 1
    }
    
    // 过滤出与当前结果重叠的层查询结果
    let filtered_results = []
    for layer_result in layer_results_array {
      let mut has_overlap = false
      for current_result in current_results {
        if ranges_overlap(layer_result.range, current_result.range) {
          // 额外的检查：确保层查询结果不是整个文件或过大的范围
          let layer_range_size = layer_result.range.end_byte() - layer_result.range.start_byte()
          let current_range_size = current_result.range.end_byte() - current_result.range.start_byte()
          
          // 如果层查询结果范围太大（超过当前结果的1.5倍），跳过它
          if layer_range_size > current_range_size * 3 / 2 {
            continue
          }
          
          // 额外的检查：确保层查询结果不是整个文件
          let content_size = content.length()
          if layer_range_size > content_size / 3 {
            continue
          }
          
          // 额外的检查：确保层查询结果与当前结果有足够的重叠
          let overlap_start = @cmp.maximum(layer_result.range.start_byte(), current_result.range.start_byte())
          let overlap_end = @cmp.minimum(layer_result.range.end_byte(), current_result.range.end_byte())
          let overlap_size = overlap_end - overlap_start
          
          // 如果重叠部分小于层查询结果的50%，跳过它
          if overlap_size < layer_range_size / 2 {
            continue
          }
          
          has_overlap = true
          break
        }
      }
      if has_overlap {
        filtered_results.push(layer_result)
      }
    }
    
    jsonrpc_result(id=id, "DEBUG: After filtering, \{filtered_results.length()} overlapping matches")
    
    // 打印所有过滤后结果的详细信息
    let mut filtered_index = 0
    for filtered_result in filtered_results {
      let start_line = filtered_result.range.start_point().row()
      let end_line = filtered_result.range.end_point().row()
      let start_col = filtered_result.range.start_point().column()
      let end_col = filtered_result.range.end_point().column()
      jsonrpc_result(id=id, "DEBUG: Filtered result \{filtered_index}: lines \{start_line}-\{end_line}, cols \{start_col}-\{end_col}")
      filtered_index = filtered_index + 1
    }
    
    // 暂时跳过去重，直接使用过滤后的结果
    current_results = filtered_results
  }
  
  Iter::new(fn(yield_) {
    for result in current_results {
      match yield_(result) {
        IterEnd => break
        IterContinue => continue
      }
    }
    IterContinue
  })
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
  content~ : @string.View,
  debug_id~ : Json
) -> Iter[Match] raise ParseError {
  let compiler = compiler()
  let root_node = compiler.parser.parse_string(content).root_node() catch {
    e => {
      jsonrpc_result(id=debug_id, "DEBUG: Parse error: \{e}")
      raise ParseError(e)
    }
  }
  
  let query = compiler.compile(query) catch {
    e => {
      jsonrpc_result(id=debug_id, "DEBUG: Query compilation error: \{e}")
      return Iter::empty()
    }
  }
  
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


