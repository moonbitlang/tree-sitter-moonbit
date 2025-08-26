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
          "params": { 
            "content": String(content), 
            "query": String(query), 
            .. 
          },
          ..
        } => {
          // Check if print_ast parameter exists, default to false if not
          let print_ast_bool = match json {
            { "params": { "print_ast": print_ast_value, .. }, .. } => @json.from_json(print_ast_value)
            _ => false
          }
          
          try {
            for result in search(query~, content~) {
              jsonrpc_result(id~, result)
            }
            
            // Return AST info based on print_ast parameter
            if print_ast_bool {
              let ast_info = get_complete_file_ast_info(content)
              let ast_result = Json::object({
                "ast_info": Json::string(ast_info),
                "print_ast_enabled": print_ast_bool.to_json()
              })
              jsonrpc_result(id~, ast_result)
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
          // Check if print_ast parameter exists, default to false if not
          let print_ast_bool = match json {
            { "params": { "print_ast": print_ast_value, .. }, .. } => @json.from_json(print_ast_value)
            _ => false
          }
          
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
          
          // Return AST info based on print_ast parameter
          if print_ast_bool {
            let ast_info = get_complete_file_ast_info(content)
            let ast_result = Json::object({
              "ast_info": Json::string(ast_info),
              "print_ast_enabled": print_ast_bool.to_json()
            })
            jsonrpc_result(id~, ast_result)
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
            "debug_mode": debug_mode,
            ..
          },
          ..
        } => {
          let captures : Map[@string.View, Array[Text]] = {}
          for name, capture_json in captures_json {
            captures[name.view()] = @json.from_json(capture_json)
          }
          
          // Extract debug mode parameter from JSON
          let debug_mode_bool = @json.from_json(debug_mode)
          
          // Check if print_ast parameter exists, default to false if not
          let print_ast_bool = match json {
            { "params": { "print_ast": print_ast_value, .. }, .. } => @json.from_json(print_ast_value)
            _ => false
          }
          
          // Execute replacement with debug mode parameter
          let replaced_content = replace(captures, replace_string, debug_mode_bool) catch {
            error => {
              jsonrpc_error(id~, error.to_json())
              return
            }
          }
          
          // Get AST info based on print_ast parameter
          let ast_info = if print_ast_bool {
            get_ast_info(replaced_content.view())
          } else {
            "AST printing disabled"
          }
          
          // Get complete file AST info based on print_ast parameter
          let complete_file_ast_info = if print_ast_bool {
            get_complete_file_ast_info(file_content)
          } else {
            "Complete file AST printing disabled"
          }
          
          // Return replacement result and AST info (content based on control parameters)
          let result = Json::object({
            "replaced": Json::string(replaced_content.to_string()),
            "ast_info": Json::string(ast_info),
            "complete_file_ast": Json::string(complete_file_ast_info),
            "print_ast_enabled": print_ast_bool.to_json()
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

          // Check if print_ast parameter exists, default to false if not
          let print_ast_bool = match json {
            { "params": { "print_ast": print_ast_value, .. }, .. } => @json.from_json(print_ast_value)
            _ => false
          }

          // Build basic debug info
          let debug_info = "DEBUG: root_type=" + root_node.type_().to_string() + 
                          ", has_error=" + has_error.to_string() + 
                          ", node_count=" + root_node.child_count().to_string() + 
                          ", text_length=" + root_node.text().length().to_string()
          
          // Add detailed AST info based on print_ast parameter
          let ast_info = if print_ast_bool {
            "\n=== DETAILED AST INFO ===\n" + get_complete_file_ast_info(content)
          } else {
            "\nAST printing disabled"
          }
          
          let full_debug_info = debug_info + ast_info
          
          // Check for syntax errors - ensure correct detection
          if has_error {
            // Return JSON-RPC error response when errors exist
            let error_message = "Syntax error detected: " + full_debug_info
            jsonrpc_error(id~, error_message.to_json())
          } else {
            // Return success response with debug info
            let success_response = Json::object({
              "status": Json::string("success"),
              "debug": Json::string(full_debug_info),
              "print_ast_enabled": print_ast_bool.to_json()
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
