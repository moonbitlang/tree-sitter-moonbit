///|
extern "c" fn getchar() -> Int = "getchar"

///|
fn main {
  let buffer = @buffer.new()
  try {
    fn on_submit() raise {
      if buffer.is_empty() {
        return
      }
      let content = @encoding.decode(buffer.contents(), encoding=UTF8)
      let json = @json.parse(content)
      
      // Parse and dispatch JSON-RPC requests
      
      match json {
        {
          "id": id,
          "method": "search",
          "params": { "content": String(content), "query": String(query), .. },
          ..
        } => {
          try {
            for result in search(query~, content~) {
              jsonrpc_result(id~, result)
            }
            jsonrpc_result(id~, Json::null())
          } catch {
            error => jsonrpc_error(id~, error.to_json())
          }
        }

        {
          "id": id,
          "method": "cascade_search",
          "params": { 
            "content": String(content), 
            "mainQuery": String(main_query), 
            "layerQueries": Array(layer_queries), 
            .. 
          },
          ..
        } => {
          let layer_queries_strings = layer_queries.map(fn(query_json) {
            match query_json {
              String(query) => query.view()
              _ => "".view()
            }
          })
          
          let mut result_count = 0
          for result in cascade_search(content~, main_query~, layer_queries_strings) {
            jsonrpc_result(id~, result.to_json())
            result_count = result_count + 1
          }
          
          jsonrpc_result(id~, Json::null())
        }
        
        {
          "id": id,
          "method": "replace",
          "params": {
            "captures": Object(captures_json),
            "replace": String(replace_string),
            "content": String(file_content),
            ..
          },
          ..
        } => {
          let captures : Map[@string.View, Array[Text]] = {}
          for name, capture_json in captures_json {
            captures[name.view()] = @json.from_json(capture_json)
          }
          
          // 执行替换
          let replaced_content = replace(captures, replace_string) catch {
            error => {
              jsonrpc_error(id~, error.to_json())
              return
            }
          }
          
          // 获取替换后内容的 AST 信息（用于调试替换结果）
          let ast_info = get_ast_info(replaced_content.view())
          
          // 获取完整文件的 AST 信息（用于控制台面板显示）
          let complete_file_ast_info = get_complete_file_ast_info(file_content)
          
          // 返回替换结果和完整的AST信息
          let result = Json::object({
            "replaced": Json::string(replaced_content.to_string()),
            "ast_info": Json::string(ast_info),
            "complete_file_ast": Json::string(complete_file_ast_info)
          })
          
          jsonrpc_result(id~, result)
        }
        
        {
          "id": id,
          "method": "validate_file_syntax",
          "params": {
            "content": String(content),
            ..
          },
          ..
        } => {
          let language = @tree_sitter_moonbit.language()
          let parser = @tree_sitter.Parser::new()
          parser.set_language(language) catch {
            _ => {
              jsonrpc_error(id~, "Failed to set language")
              return
            }
          }
          
          let tree = parser.parse_string(content) catch {
            _ => {
              jsonrpc_error(id~, "Failed to parse file")
              return
            }
          }
          
          let root_node = tree.root_node()
          let has_error = root_node.has_error()

          // 构建调试信息
          let debug_info = "DEBUG: root_type=" + root_node.type_().to_string() + 
                          ", has_error=" + has_error.to_string() + 
                          ", node_count=" + root_node.child_count().to_string() + 
                          ", text_length=" + root_node.text().to_string().length().to_string()
          
          // 检查是否有语法错误 - 确保正确检测
          if has_error {
            // 有错误时返回 JSON-RPC 错误响应
            let error_message = "Syntax error detected: " + debug_info
            jsonrpc_error(id~, error_message.to_json())
          } else {
            // 成功时返回包含调试信息的对象
            let success_response = Json::object({
              "status": Json::string("success"),
              "debug": Json::string(debug_info)
            })
            jsonrpc_result(id~, success_response)
          }
        }
        
        { "id": id, .. } =>
          jsonrpc_error(id~, "Invalid request: \{json.to_json().stringify()}")
        _ =>
          jsonrpc_error(
            id=Json::null(),
            "Invalid request: \{json.to_json().stringify()}",
          )
      }
      buffer.reset()
    }

    loop getchar() {
      '\n' => {
        on_submit() catch {
          error => jsonrpc_error(id=Json::null(), error.to_string().to_json())
        }
        continue getchar()
      }
      0..<_ as byte => {
        buffer.write_byte(byte.to_byte())
        continue getchar()
      }
      _..<0 => on_submit()
    }
  } catch {
    error => jsonrpc_error(id=Json::null(), error.to_string().to_json())
  }
}
