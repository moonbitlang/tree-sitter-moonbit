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
      
      // 注释掉早期debug消息，因为此时还没有解析出id
      // jsonrpc_result(id=Json::null(), "DEBUG: Received request: \{json.to_json().stringify()}")
      
      // 检查是否是 multiLayerSearch 请求
      let _ = match json {
        {
          "method": String(_method),
          ..
        } => {
          // 注释掉早期debug消息，因为此时还没有解析出id
          // if _method == "multiLayerSearch" {
          //   jsonrpc_result(id=Json::null(), "DEBUG: Found multiLayerSearch method")
          // } else {
          //   jsonrpc_result(id=Json::null(), "DEBUG: Not multiLayerSearch method, method is: \{_method}")
          // }
        }
        _ => {
          // 注释掉早期debug消息，因为此时还没有解析出id
          // jsonrpc_result(id=Json::null(), "DEBUG: Not multiLayerSearch method, no method field")
        }
      }
      
      match json {
        {
          "id": id,
          "method": "search",
          "params": { "content": String(content), "query": String(query), .. },
          ..
        } => {
          // 注释掉debug消息，因为search函数内部已经有足够的debug信息
          // jsonrpc_result(id=Json::null(), "DEBUG: Processing search method")
          try {
            for result in search(query~, content~, debug_id=id) {
              jsonrpc_result(id~, result)
            }
            jsonrpc_result(id~, Json::null())
          } catch {
            error => jsonrpc_error(id~, error.to_json())
          }
        }
        {
          "id": id,
          "method": "multiLayerSearch",
          "params": { 
            "content": String(content), 
            "mainQuery": String(main_query), 
            "layerQueries": Array(layer_queries), 
            .. 
          },
          ..
        } => {
          jsonrpc_result(id~, "DEBUG: Processing multiLayerSearch method")
          
          // 转换 layer_queries 从 Array[Json] 到 Array[@string.View]
          let layer_queries_strings = layer_queries.map(fn(query_json) {
            match query_json {
              String(query) => query.view()
              _ => "".view()
            }
          })
          
          // 添加调试日志
          jsonrpc_result(id~, Json::string("DEBUG: Starting multi_layer_search"))
          
          // 添加更多调试信息
          jsonrpc_result(id~, Json::string("DEBUG: Main query: \{main_query}"))
          jsonrpc_result(id~, Json::string("DEBUG: Layer queries count: \{layer_queries_strings.length()}"))
          jsonrpc_result(id~, Json::string("DEBUG: Content length: \{content.length()}"))
          
          jsonrpc_result(id~, Json::string("DEBUG: About to call multi_layer_search"))
          jsonrpc_result(id~, Json::string("DEBUG: Layer queries count: \{layer_queries_strings.length()}"))
          jsonrpc_result(id~, Json::string("DEBUG: First layer query: \{layer_queries_strings[0]}"))

          let mut result_count = 0
          for result in multi_layer_search(content~, main_query~, layer_queries_strings, id~) {
            jsonrpc_result(id~, result.to_json())
            result_count = result_count + 1
            if result_count % 10 == 0 {
              jsonrpc_result(id~, Json::string("DEBUG: Processed \{result_count} results so far"))
            }
          }
          jsonrpc_result(id~, Json::string("DEBUG: Finished iterating over multi_layer_search results"))
          
          // 添加调试日志
          jsonrpc_result(id~, Json::string("DEBUG: multi_layer_search completed with \{result_count} results"))
          jsonrpc_result(id~, Json::null())
        }
        {
          "id": id,
          "method": "replace",
          "params": {
            "captures": Object(captures_json),
            "replace": String(replace_string),
            ..
          },
          ..
        } => {
          let captures : Map[@string.View, Array[Text]] = {}
          for name, capture_json in captures_json {
            captures[name.view()] = @json.from_json(capture_json)
          }
          jsonrpc_result(id~, replace(captures, replace_string)) catch {
            error => jsonrpc_error(id~, error.to_json())
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
