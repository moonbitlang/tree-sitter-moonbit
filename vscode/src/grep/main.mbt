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
      
      // 解析并分发 JSON-RPC 请求
      
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
          
          // 添加调试信息
      
          
          let mut result_count = 0
          for result in cascade_search(content~, main_query~, layer_queries_strings) {
            jsonrpc_result(id~, result.to_json())
            result_count = result_count + 1
            
            // 调试：打印每个结果的节点信息（简化格式）
            
          }
          
          // 显示最终结果数量
      
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
