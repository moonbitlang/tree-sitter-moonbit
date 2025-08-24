///|
// 辅助函数：获取两个数中的较小值
fn min(a : Int, b : Int) -> Int {
  if a < b { a } else { b }
}

///|
priv enum Replace {
  Quote(String)
  Subst(String)
}

///|
suberror ReplaceError {
  VariableNotFound(String)
  MismatchedType(expect~ : String, actual~ : String)
} derive(Show, ToJson(style="legacy"))

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
// 新增：打印 AST 所有节点的辅助函数
fn print_ast_nodes(
  node : @tree_sitter.Node,
  depth : Int,
  buffer : StringBuilder
) -> Unit {
  // 缩进
  for i = 0; i < depth; i = i + 1 {
    buffer.write_string("  ")
  }
  
  // 节点类型和属性
  let node_type = node.type_().to_string()
  let is_named = node.is_named()
  let child_count = node.child_count()
  let text = node.text().to_string()
  
  buffer.write_string("Node: type='\{node_type}', named=\{is_named}, children=\{child_count}, text='\{text}'\n")
  
  // 递归打印子节点
  for i = 0; i < child_count; i = i + 1 {
    let child = node.child(i)
    if child is Some(_) {
      print_ast_nodes(child.unwrap(), depth + 1, buffer)
    }
  }
}

///|
// 新增：获取完整 AST 信息的函数
fn get_ast_info(content : @string.View) -> String {
  let language = @tree_sitter_moonbit.language()
  let parser = @tree_sitter.Parser::new()
  
  // 尝试设置语言
  parser.set_language(language) catch {
    _ => return "ERROR: Failed to set language"
  }
  
  // 尝试解析内容
  let tree = parser.parse_string(content) catch {
    _ => return "ERROR: Failed to parse content"
  }
  
  let root_node = tree.root_node()
  let has_error = root_node.has_error()
  
  let buffer = StringBuilder::new()
  buffer.write_string("=== COMPLETE FILE AST ANALYSIS ===\n")
  buffer.write_string("Root node type: \{root_node.type_().to_string()}\n")
  buffer.write_string("Has error: \{has_error}\n")
  buffer.write_string("Total children: \{root_node.child_count()}\n")
  buffer.write_string("Content length: \{content.to_string().length()}\n")
  buffer.write_string("Content preview: \{content.to_string().substring(start=0, end=min(100, content.to_string().length()))}\n")
  
  if content.to_string().length() > 100 {
    buffer.write_string("... (truncated for preview)\n")
  }
  
  buffer.write_string("\n=== COMPLETE AST STRUCTURE ===\n")
  
  // 打印完整的AST结构
  print_ast_nodes(root_node, 0, buffer)
  
  buffer.write_string("=== END COMPLETE AST ===\n")
  return buffer.to_string()
}

///|
// 新增：获取完整文件AST信息的函数（专门用于文件分析）
fn get_complete_file_ast_info(content : @string.View) -> String {
  let language = @tree_sitter_moonbit.language()
  let parser = @tree_sitter.Parser::new()
  
  // 尝试设置语言
  parser.set_language(language) catch {
    _ => return "ERROR: Failed to set language"
  }
  
  // 尝试解析完整文件内容
  let tree = parser.parse_string(content) catch {
    _ => return "ERROR: Failed to parse file content"
  }
  
  let root_node = tree.root_node()
  let has_error = root_node.has_error()
  
  let buffer = StringBuilder::new()
  buffer.write_string("=== COMPLETE FILE AST ANALYSIS ===\n")
  buffer.write_string("Root node type: \{root_node.type_().to_string()}\n")
  buffer.write_string("Has error: \{has_error}\n")
  buffer.write_string("Total children: \{root_node.child_count()}\n")
  buffer.write_string("File content length: \{content.to_string().length()}\n")
  buffer.write_string("File content preview: \{content.to_string().substring(start=0, end=min(200, content.to_string().length()))}\n")
  
  if content.to_string().length() > 200 {
    buffer.write_string("... (truncated for preview)\n")
  }
  
  buffer.write_string("\n=== COMPLETE FILE AST STRUCTURE ===\n")
  
  // 打印完整的文件AST结构
  print_ast_nodes(root_node, 0, buffer)
  
  buffer.write_string("=== END COMPLETE FILE AST ===\n")
  return buffer.to_string()
}

///|
fn replace(
  captures : Map[@string.View, Array[Text]],
  replace : @string.View
) -> @string.View raise ReplaceError {

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

///|
priv struct Text {
  range : @tree_sitter.Range
  text : @string.View
}

///|
impl ToJson for Text with to_json(self : Text) -> Json {
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
impl @json.FromJson for Text with from_json(self : Json, path : @json.JsonPath) -> Text raise @json.JsonDecodeError {
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


