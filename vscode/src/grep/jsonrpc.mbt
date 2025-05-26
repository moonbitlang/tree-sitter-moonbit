///|
fn[Result : ToJson] jsonrpc_result(id~ : Json, result : Result) -> Unit {
  let response : Json = {
    "jsonrpc": "2.0",
    "result": result.to_json(),
    "id": id,
  }
  println(response.stringify())
}

///|
fn jsonrpc_error(id~ : Json, error : String) -> Unit {
  let response : Json = {
    "jsonrpc": "2.0",
    "error": { "code": -32603, "message": error.to_json() },
    "id": id,
  }
  println(response.stringify())
}
