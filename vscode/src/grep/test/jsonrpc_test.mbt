///|
test "grep" {
  let requests : Array[Map[String, Json]] = [
    {
      "jsonrpc": "2.0",
      "id": 0,
      "method": "search",
      "params": {
        "query": "$exp:a + $exp:b",
        "content": "fn main {\n  1 + 2\n}",
      },
    },
    {
      "jsonrpc": "2.0",
      "id": 1,
      "method": "search",
      "params": {
        "query": "$exp:a + $exp:a",
        "content": "fn main {\n  1 + 2\n}",
      },
    },
    {
      "jsonrpc": "2.0",
      "id": 2,
      "method": "search",
      "params": {
        "query": "fn main {\n  $exp:a\n  $...\n}",
        "content": "fn main {\n  1 + 2\n}",
      },
    },
    {
      "jsonrpc": "2.0",
      "id": 3,
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
    {
      "jsonrpc": "2.0",
      "id": "d3605573-9477-499d-bdfc-7a5fe0664568",
      "method": "search",
      "params": {
        "query": "fn main {\n  $exp:a\n} ",
        "content": "fn main {\n  1 + 2\n}\n",
      },
    },
  ]
  let request = requests
    .map(fn(request) { request.to_json().stringify() })
    .join("\n")
    |> @encoding.encode(encoding=UTF8)
  let null = Json::null()
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
      { "jsonrpc": "2.0", "result": null, "id": 0 },
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
          },
        },
        "id": 1,
      },
      { "jsonrpc": "2.0", "result": null, "id": 1 },
      {
        "jsonrpc": "2.0",
        "result": {
          "range": {
            "start": { "row": 0, "column": 0, "byte": 0 },
            "end": { "row": 2, "column": 1, "byte": 19 },
          },
          "captures": {
            "a": [
              {
                "range": {
                  "start": { "row": 1, "column": 2, "byte": 12 },
                  "end": { "row": 1, "column": 7, "byte": 17 },
                },
                "text": "1 + 2",
              },
            ],
          },
        },
        "id": 2,
      },
      { "jsonrpc": "2.0", "result": null, "id": 2 },
      { "jsonrpc": "2.0", "result": "2 + 1", "id": 3 },
      {
        "jsonrpc": "2.0",
        "result": {
          "range": {
            "start": { "row": 0, "column": 0, "byte": 0 },
            "end": { "row": 2, "column": 1, "byte": 19 },
          },
          "captures": {
            "a": [
              {
                "range": {
                  "start": { "row": 1, "column": 2, "byte": 12 },
                  "end": { "row": 1, "column": 7, "byte": 17 },
                },
                "text": "1 + 2",
              },
            ],
          },
        },
        "id": "d3605573-9477-499d-bdfc-7a5fe0664568",
      },
      {
        "jsonrpc": "2.0",
        "result": null,
        "id": "d3605573-9477-499d-bdfc-7a5fe0664568",
      },
    ])
  })
}
