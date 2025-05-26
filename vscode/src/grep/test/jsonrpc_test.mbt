///|
test "grep" {
  let requests : Array[Map[String, Json]] = [
    {
      "jsonrpc": "2.0",
      "method": "search",
      "params": {
        "query": "$exp:a + $exp:b",
        "content": "fn main {\n  1 + 2\n}",
      },
    },
    {
      "jsonrpc": "2.0",
      "method": "replace",
      "params": {
        "captures": {
          "a": [
            {
              "range": {
                "start": { "row": 1, "column": 2, "byte": 12 },
                "end": { "row": 1, "column": 3, "byte": 13 },
              },
              "text": "1",
            },
          ],
          "b": [
            {
              "range": {
                "start": { "row": 1, "column": 6, "byte": 16 },
                "end": { "row": 1, "column": 7, "byte": 17 },
              },
              "text": "2",
            },
          ],
        },
        "replace": "$b + $a",
      },
    },
  ]
  let id_ref = Ref::new(0)
  let request = requests
    .map(fn(request) {
      let id = id_ref.val
      id_ref.val = id + 1
      request["id"] = id.to_json()
      request.to_json().stringify()
    })
    .join("\n")
    |> @encoding.encode(encoding=UTF8)
  @async.start!(fn() {
    let stdout = @buffer.new()
    let process = @async.spawn!(
      "moon",
      ["run", @async.path!(["src", "grep"]), "--target", "native"],
      stdin=Bytes(request),
      stdout=Buffer(stdout),
    )
    @json.inspect!(process.status(), content=0)
    let response = []
    for line in @encoding.decode!(stdout.contents(), encoding=UTF8).split("\n") {
      if line.is_empty() {
        continue
      }
      response.push(@json.parse!(line.to_string()))
    }
    @json.inspect!(response, content=[
      {
        "jsonrpc": "2.0",
        "result": {
          "range": {
            "start": { "row": 1, "column": 2, "byte": 12 },
            "end": { "row": 1, "column": 7, "byte": 17 },
          },
          "captures": {
            "a": [
              {
                "range": {
                  "start": { "row": 1, "column": 2, "byte": 12 },
                  "end": { "row": 1, "column": 3, "byte": 13 },
                },
                "text": "1",
              },
            ],
            "b": [
              {
                "range": {
                  "start": { "row": 1, "column": 6, "byte": 16 },
                  "end": { "row": 1, "column": 7, "byte": 17 },
                },
                "text": "2",
              },
            ],
          },
        },
        "id": 0,
      },
      { "jsonrpc": "2.0", "result": "2 + 1", "id": 1 },
    ])
  })
}
