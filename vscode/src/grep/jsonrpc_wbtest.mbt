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
      "id": 4,
      "method": "search",
      "params": {
        "query": "fn main {\n  $exp:a\n} ",
        "content": "fn main {\n  1 + 2\n}\n",
      },
    },
    {
      "jsonrpc": "2.0",
      "id": 5,
      "method": "search",
      "params": {
        "query": #|for $id:i = 0; $id:i < 10; $id:i = $id:i + 1 {
        #|  $exp:a
        #|}
        ,
        "content": #|fn main {
        #|  for i = 0; i < 10; i = i + 1 {
        #|    println("Hello, world")
        #|  }
        #|}
        ,
      },
    },
  ]
  let request = requests
    .map(fn(request) { request.to_json().stringify() })
    .join("\n")
  let null = Json::null()
  @async.start!(fn() {
    let stdin = @async.Pipe::new()
    let stdout = @async.Pipe::new()
    let process = @async.spawn!(
      "moon",
      ["run", @async.path(["src", "grep"]), "--target", "native"],
      stdin=Pipe(stdin),
      stdout=Pipe(stdout),
    )
    stdin.write_text(request, encoding=UTF8)
    stdin.close()
    @json.inspect!(process.status(), content=0)
    let response = []
    for line in stdout.read_text(encoding=UTF8).split("\n") {
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
        "id": 4,
      },
      { "jsonrpc": "2.0", "result": null, "id": 4 },
      {
        "jsonrpc": "2.0",
        "result": {
          "range": {
            "start": { "row": 1, "column": 2, "byte": 12 },
            "end": { "row": 3, "column": 3, "byte": 74 },
          },
          "captures": {
            "i": [
              {
                "range": {
                  "start": { "row": 1, "column": 6, "byte": 16 },
                  "end": { "row": 1, "column": 7, "byte": 17 },
                },
                "text": "i",
              },
            ],
            "a": [
              {
                "range": {
                  "start": { "row": 2, "column": 4, "byte": 47 },
                  "end": { "row": 2, "column": 27, "byte": 70 },
                },
                "text": "println(\"Hello, world\")",
              },
            ],
          },
        },
        "id": 5,
      },
      { "jsonrpc": "2.0", "result": null, "id": 5 },
    ])
  })
}
