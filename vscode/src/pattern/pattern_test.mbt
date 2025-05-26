///|
fn moonbit() -> @pattern.Language! {
  let language = @tree_sitter_moonbit.language()
  let contexts : Map[String, @pattern.Context] = {
    "exp": @pattern.Context::new!(
      #|fn main {
      #|  $
      #|}
      ,
      strip=true,
      selector=
        #|(structure
        #| (structure_item
        #|  (function_definition
        #|   (block_expression
        #|    "{"
        #|    (statement_expression
        #|     (_) @exp)
        #|    "}"))))
      ,
    ),
    "top": @pattern.Context::new!(
      "$",
      selector=
        #|(structure_item) @top
      ,
    ),
    "pat": @pattern.Context::new!(
      #|fn main {
      #|  match x {
      #|    $ => y
      #|  }
      #|}
      ,
      selector=
        #|(pattern) @pat
      ,
    ),
    "ty": @pattern.Context::new!(
      #|let x : $ = 42
      ,
      selector=
        #|(type) @ty
      ,
    ),
    "case": @pattern.Context::new!(
      #|fn main {
      #|  match x {
      #|    $
      #|  }
      #|}
      ,
      selector=
        #|(case_clause) @case
      ,
    ),
    "matrix": @pattern.Context::new!(
      #|fn main {
      #|  loop a, b {
      #|    $
      #|  }
      #|}
      ,
      selector=
        #|(matrix_case_clause) @matrix
      ,
    ),
  }
  let entries : Map[String, @pattern.Entry] = {
    "exp": @pattern.Entry::new(
      name="exp",
      selector=
        #|[
        #|  (expression)
        #|  (pipeline_expression)
        #|  (compound_expression)
        #|  (match_expression)
        #|  (named_matrix_expression)
        #|  (guard_expression)
        #|  (statement_expression)
        #|  (simple_expression)
        #|] @exp
      ,
      placeholder="{...}",
    ),
    "top": @pattern.Entry::new(
      name="top",
      selector=
        #|[
        #|  (structure_item)
        #|] @top
      ,
      placeholder=
        #|type! A Int
      ,
    ),
    "pat": @pattern.Entry::new(
      name="pat",
      selector=
        #|[
        #|  (pattern)
        #|  (simple_pattern)
        #|] @pat
      ,
      placeholder="_",
    ),
    "id": @pattern.Entry::new(
      name="id",
      selector=
        #|[
        #|  (identifier)
        #|  (lowercase_identifier)
        #|  (uppercase_identifier)
        #|  (qualified_identifier)
        #|  (constructor_expression)
        #|] @id
      ,
      placeholder="id",
    ),
    "ty": @pattern.Entry::new(
      name="ty",
      selector=
        #|[
        #|  (type)
        #|  (return_type)
        #|] @ty
      ,
      placeholder="A",
    ),
  }
  let extras = ["semicolon"]
  @pattern.Language::new!(language, contexts~, entries~, extras~)
}

///|
test "exp" {
  let query =
    #|$exp:a == $exp:b
  let query = moonbit!().compile!(query)
  let matches = query.search!(
    #|fn main {
    #|  1 == 2
    #|}
    #|
    #|let a : Bool = 3 == 4
    ,
  )
  @json.inspect!(matches.collect(), content=[
    {
      "range": {
        "start": { "row": 1, "column": 2, "byte": 12 },
        "end": { "row": 1, "column": 8, "byte": 18 },
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
              "start": { "row": 1, "column": 7, "byte": 17 },
              "end": { "row": 1, "column": 8, "byte": 18 },
            },
            "text": "2",
          },
        ],
      },
    },
    {
      "range": {
        "start": { "row": 4, "column": 15, "byte": 37 },
        "end": { "row": 4, "column": 21, "byte": 43 },
      },
      "captures": {
        "a": [
          {
            "range": {
              "start": { "row": 4, "column": 15, "byte": 37 },
              "end": { "row": 4, "column": 16, "byte": 38 },
            },
            "text": "3",
          },
        ],
        "b": [
          {
            "range": {
              "start": { "row": 4, "column": 20, "byte": 42 },
              "end": { "row": 4, "column": 21, "byte": 43 },
            },
            "text": "4",
          },
        ],
      },
    },
  ])
}

///|
test "top" {
  let query =
    #|fn main {
    #|  println($exp:a)
    #|}
  let query = moonbit!().compile!(query)
  let matches = query.search!(
    #|fn main {
    #|  println("Hello, world!")
    #|}
    #|
    #|fn foo {
    #|  println("Hello, world!")
    #|}
    ,
  )
  @json.inspect!(matches.collect(), content=[
    {
      "range": {
        "start": { "row": 0, "column": 0, "byte": 0 },
        "end": { "row": 2, "column": 1, "byte": 38 },
      },
      "captures": {
        "a": [
          {
            "range": {
              "start": { "row": 1, "column": 10, "byte": 20 },
              "end": { "row": 1, "column": 25, "byte": 35 },
            },
            "text": "\"Hello, world!\"",
          },
        ],
      },
    },
  ])
}

///|
test "fn_ambiguity" {
  let query =
    #|fn $id:a {
    #|}
  let query = moonbit!().compile!(query)
  let source =
    #|fn f(x : Int) -> Unit {
    #|  fn fx {
    #|  }
    #|}
    #|
    #|let a : Int = {
    #|  fn fa {
    #|  }
    #|}
    #|
    #|fn main {
    #|}
  let matches = query.search!(source)
  @json.inspect!(matches.collect(), content=[
    {
      "range": {
        "start": { "row": 1, "column": 2, "byte": 26 },
        "end": { "row": 2, "column": 3, "byte": 37 },
      },
      "captures": {
        "a": [
          {
            "range": {
              "start": { "row": 1, "column": 5, "byte": 29 },
              "end": { "row": 1, "column": 7, "byte": 31 },
            },
            "text": "fx",
          },
        ],
      },
    },
    {
      "range": {
        "start": { "row": 6, "column": 2, "byte": 59 },
        "end": { "row": 7, "column": 3, "byte": 70 },
      },
      "captures": {
        "a": [
          {
            "range": {
              "start": { "row": 6, "column": 5, "byte": 62 },
              "end": { "row": 6, "column": 7, "byte": 64 },
            },
            "text": "fa",
          },
        ],
      },
    },
    {
      "range": {
        "start": { "row": 10, "column": 0, "byte": 74 },
        "end": { "row": 11, "column": 1, "byte": 85 },
      },
      "captures": {
        "a": [
          {
            "range": {
              "start": { "row": 10, "column": 3, "byte": 77 },
              "end": { "row": 10, "column": 7, "byte": 81 },
            },
            "text": "main",
          },
        ],
      },
    },
  ])
}

///|
test "concat" {
  let query =
    #|match $exp:a {
    #|  $pat:b => $exp:c
    #|}
    #|$exp:d
    #|return $exp:f
  let query = moonbit!().compile!(query)
  let matches = query.search!(
    #|fn main {
    #|  match x {
    #|    y => z
    #|  }
    #|  println("a")
    #|  return 3
    #|}
    ,
  )
  @json.inspect!(matches.collect(), content=[
    {
      "range": {
        "start": { "row": 1, "column": 2, "byte": 12 },
        "end": { "row": 5, "column": 10, "byte": 62 },
      },
      "captures": {
        "a": [
          {
            "range": {
              "start": { "row": 1, "column": 8, "byte": 18 },
              "end": { "row": 1, "column": 9, "byte": 19 },
            },
            "text": "x",
          },
        ],
        "b": [
          {
            "range": {
              "start": { "row": 2, "column": 4, "byte": 26 },
              "end": { "row": 2, "column": 5, "byte": 27 },
            },
            "text": "y",
          },
        ],
        "c": [
          {
            "range": {
              "start": { "row": 2, "column": 9, "byte": 31 },
              "end": { "row": 2, "column": 10, "byte": 32 },
            },
            "text": "z",
          },
        ],
        "d": [
          {
            "range": {
              "start": { "row": 4, "column": 2, "byte": 39 },
              "end": { "row": 4, "column": 14, "byte": 51 },
            },
            "text": "println(\"a\")",
          },
        ],
        "f": [
          {
            "range": {
              "start": { "row": 5, "column": 9, "byte": 61 },
              "end": { "row": 5, "column": 10, "byte": 62 },
            },
            "text": "3",
          },
        ],
      },
    },
  ])
}

///|
test "ty" {
  let query =
    #|let $id:a : $ty:b = $exp:c
  let query = moonbit!().compile!(query)
  let matches = query.search!(
    #|let a : Int = 42
    #|
    #|fn main {
    #|  let b : Bool = true
    #|}
    ,
  )
  @json.inspect!(matches.collect(), content=[
    {
      "range": {
        "start": { "row": 0, "column": 0, "byte": 0 },
        "end": { "row": 0, "column": 16, "byte": 16 },
      },
      "captures": {
        "a": [
          {
            "range": {
              "start": { "row": 0, "column": 4, "byte": 4 },
              "end": { "row": 0, "column": 5, "byte": 5 },
            },
            "text": "a",
          },
        ],
        "b": [
          {
            "range": {
              "start": { "row": 0, "column": 8, "byte": 8 },
              "end": { "row": 0, "column": 11, "byte": 11 },
            },
            "text": "Int",
          },
        ],
        "c": [
          {
            "range": {
              "start": { "row": 0, "column": 14, "byte": 14 },
              "end": { "row": 0, "column": 16, "byte": 16 },
            },
            "text": "42",
          },
        ],
      },
    },
    {
      "range": {
        "start": { "row": 3, "column": 2, "byte": 30 },
        "end": { "row": 3, "column": 21, "byte": 49 },
      },
      "captures": {
        "a": [
          {
            "range": {
              "start": { "row": 3, "column": 6, "byte": 34 },
              "end": { "row": 3, "column": 7, "byte": 35 },
            },
            "text": "b",
          },
        ],
        "b": [
          {
            "range": {
              "start": { "row": 3, "column": 10, "byte": 38 },
              "end": { "row": 3, "column": 14, "byte": 42 },
            },
            "text": "Bool",
          },
        ],
        "c": [
          {
            "range": {
              "start": { "row": 3, "column": 17, "byte": 45 },
              "end": { "row": 3, "column": 21, "byte": 49 },
            },
            "text": "true",
          },
        ],
      },
    },
  ])
}

///|
test "id" {
  let query =
    #|match a {
    #|  $id:a => $exp:b
    #|}
  let query = moonbit!().compile!(query)
  let matches = query.search!(
    #|fn main {
    #|  match a {
    #|    A => 1
    #|  }
    #|  match a {
    #|    a => 2
    #|  }
    #|}
    ,
  )
  @json.inspect!(matches.collect(), content=[
    {
      "range": {
        "start": { "row": 4, "column": 2, "byte": 39 },
        "end": { "row": 6, "column": 3, "byte": 63 },
      },
      "captures": {
        "a": [
          {
            "range": {
              "start": { "row": 5, "column": 4, "byte": 53 },
              "end": { "row": 5, "column": 5, "byte": 54 },
            },
            "text": "a",
          },
        ],
        "b": [
          {
            "range": {
              "start": { "row": 5, "column": 9, "byte": 58 },
              "end": { "row": 5, "column": 10, "byte": 59 },
            },
            "text": "2",
          },
        ],
      },
    },
  ])
}

///|
test "quantifier" {
  let query =
    #|guard $exp:a is $pat:b else {
    #|  ${
    #|    $exp:c
    #|  }*
    #|  return $exp:d
    #|}
  let query = moonbit!().compile!(query)
  let matches = query.search!(
    #|fn main {
    #|  guard a is None else {
    #|    return 3
    #|  }
    #|  guard a is Some else {
    #|    println("a")
    #|    return 4
    #|  }
    #|  guard a is Some else {
    #|    println("a")
    #|    println("b")
    #|    return 5
    #|  }
    #|}
    ,
  )
  @json.inspect!(matches.collect(), content=[
    {
      "range": {
        "start": { "row": 1, "column": 2, "byte": 12 },
        "end": { "row": 3, "column": 3, "byte": 51 },
      },
      "captures": {
        "a": [
          {
            "range": {
              "start": { "row": 1, "column": 8, "byte": 18 },
              "end": { "row": 1, "column": 9, "byte": 19 },
            },
            "text": "a",
          },
        ],
        "b": [
          {
            "range": {
              "start": { "row": 1, "column": 13, "byte": 23 },
              "end": { "row": 1, "column": 17, "byte": 27 },
            },
            "text": "None",
          },
        ],
        "d": [
          {
            "range": {
              "start": { "row": 2, "column": 11, "byte": 46 },
              "end": { "row": 2, "column": 12, "byte": 47 },
            },
            "text": "3",
          },
        ],
      },
    },
    {
      "range": {
        "start": { "row": 4, "column": 2, "byte": 54 },
        "end": { "row": 7, "column": 3, "byte": 110 },
      },
      "captures": {
        "a": [
          {
            "range": {
              "start": { "row": 4, "column": 8, "byte": 60 },
              "end": { "row": 4, "column": 9, "byte": 61 },
            },
            "text": "a",
          },
        ],
        "b": [
          {
            "range": {
              "start": { "row": 4, "column": 13, "byte": 65 },
              "end": { "row": 4, "column": 17, "byte": 69 },
            },
            "text": "Some",
          },
        ],
        "c": [
          {
            "range": {
              "start": { "row": 5, "column": 4, "byte": 81 },
              "end": { "row": 5, "column": 16, "byte": 93 },
            },
            "text": "println(\"a\")",
          },
        ],
        "d": [
          {
            "range": {
              "start": { "row": 6, "column": 11, "byte": 105 },
              "end": { "row": 6, "column": 12, "byte": 106 },
            },
            "text": "4",
          },
        ],
      },
    },
    {
      "range": {
        "start": { "row": 8, "column": 2, "byte": 113 },
        "end": { "row": 12, "column": 3, "byte": 186 },
      },
      "captures": {
        "a": [
          {
            "range": {
              "start": { "row": 8, "column": 8, "byte": 119 },
              "end": { "row": 8, "column": 9, "byte": 120 },
            },
            "text": "a",
          },
        ],
        "b": [
          {
            "range": {
              "start": { "row": 8, "column": 13, "byte": 124 },
              "end": { "row": 8, "column": 17, "byte": 128 },
            },
            "text": "Some",
          },
        ],
        "c": [
          {
            "range": {
              "start": { "row": 9, "column": 4, "byte": 140 },
              "end": { "row": 9, "column": 16, "byte": 152 },
            },
            "text": "println(\"a\")",
          },
          {
            "range": {
              "start": { "row": 10, "column": 4, "byte": 157 },
              "end": { "row": 10, "column": 16, "byte": 169 },
            },
            "text": "println(\"b\")",
          },
        ],
        "d": [
          {
            "range": {
              "start": { "row": 11, "column": 11, "byte": 181 },
              "end": { "row": 11, "column": 12, "byte": 182 },
            },
            "text": "5",
          },
        ],
      },
    },
  ])
}

///|
test "group" {
  let query =
    #|[${ $exp:x, }+ $exp:x]
  let query = moonbit!().compile!(query)
  let matches = query.search!(
    #|fn main {
    #|  [0]
    #|  [0, 1]
    #|  [0, 1, 2]
    #|}
    ,
  )
  @json.inspect!(matches.collect(), content=[
    {
      "range": {
        "start": { "row": 2, "column": 2, "byte": 18 },
        "end": { "row": 2, "column": 8, "byte": 24 },
      },
      "captures": {
        "x": [
          {
            "range": {
              "start": { "row": 2, "column": 3, "byte": 19 },
              "end": { "row": 2, "column": 4, "byte": 20 },
            },
            "text": "0",
          },
          {
            "range": {
              "start": { "row": 2, "column": 6, "byte": 22 },
              "end": { "row": 2, "column": 7, "byte": 23 },
            },
            "text": "1",
          },
        ],
      },
    },
    {
      "range": {
        "start": { "row": 3, "column": 2, "byte": 27 },
        "end": { "row": 3, "column": 11, "byte": 36 },
      },
      "captures": {
        "x": [
          {
            "range": {
              "start": { "row": 3, "column": 3, "byte": 28 },
              "end": { "row": 3, "column": 4, "byte": 29 },
            },
            "text": "0",
          },
          {
            "range": {
              "start": { "row": 3, "column": 6, "byte": 31 },
              "end": { "row": 3, "column": 7, "byte": 32 },
            },
            "text": "1",
          },
          {
            "range": {
              "start": { "row": 3, "column": 9, "byte": 34 },
              "end": { "row": 3, "column": 10, "byte": 35 },
            },
            "text": "2",
          },
        ],
      },
    },
  ])
}

///|
test "case" {
  let query =
    #|${ $pat:a, }* $pat:a => $exp:b
  let query = moonbit!().compile!(query)
  let matches = query.search!(
    #|fn main {
    #|  match a {
    #|    A => 1
    #|  }
    #|  fn b {
    #|    B => 2
    #|  }
    #|  loop c, d {
    #|    C, D => 3
    #|  }
    #|}
    ,
  )
  @json.inspect!(matches.collect(), content=[
    {
      "range": {
        "start": { "row": 5, "column": 4, "byte": 50 },
        "end": { "row": 5, "column": 10, "byte": 56 },
      },
      "captures": {
        "a": [
          {
            "range": {
              "start": { "row": 5, "column": 4, "byte": 50 },
              "end": { "row": 5, "column": 5, "byte": 51 },
            },
            "text": "B",
          },
        ],
        "b": [
          {
            "range": {
              "start": { "row": 5, "column": 9, "byte": 55 },
              "end": { "row": 5, "column": 10, "byte": 56 },
            },
            "text": "2",
          },
        ],
      },
    },
    {
      "range": {
        "start": { "row": 8, "column": 4, "byte": 79 },
        "end": { "row": 8, "column": 13, "byte": 88 },
      },
      "captures": {
        "a": [
          {
            "range": {
              "start": { "row": 8, "column": 4, "byte": 79 },
              "end": { "row": 8, "column": 5, "byte": 80 },
            },
            "text": "C",
          },
          {
            "range": {
              "start": { "row": 8, "column": 7, "byte": 82 },
              "end": { "row": 8, "column": 8, "byte": 83 },
            },
            "text": "D",
          },
        ],
        "b": [
          {
            "range": {
              "start": { "row": 8, "column": 12, "byte": 87 },
              "end": { "row": 8, "column": 13, "byte": 88 },
            },
            "text": "3",
          },
        ],
      },
    },
  ])
}

///|
test "escape" {
  let query =
    #|${
    #|fn init \{
    #|  ${
    #|    $exp:a
    #|  }*
    #|\}
    #|}+
  let query = moonbit!().compile!(query)
  let matches = query.search!(
    #|fn init {
    #|  println("Hello")
    #|}
    #|
    #|fn init {
    #|  println("World")
    #|  println("!")
    #|}
    ,
  )
  @json.inspect!(matches.collect(), content=[
    {
      "range": {
        "start": { "row": 0, "column": 0, "byte": 0 },
        "end": { "row": 2, "column": 1, "byte": 30 },
      },
      "captures": {
        "a": [
          {
            "range": {
              "start": { "row": 1, "column": 2, "byte": 12 },
              "end": { "row": 1, "column": 18, "byte": 28 },
            },
            "text": "println(\"Hello\")",
          },
        ],
      },
    },
    {
      "range": {
        "start": { "row": 4, "column": 0, "byte": 32 },
        "end": { "row": 7, "column": 1, "byte": 77 },
      },
      "captures": {
        "a": [
          {
            "range": {
              "start": { "row": 5, "column": 2, "byte": 44 },
              "end": { "row": 5, "column": 18, "byte": 60 },
            },
            "text": "println(\"World\")",
          },
          {
            "range": {
              "start": { "row": 6, "column": 2, "byte": 63 },
              "end": { "row": 6, "column": 14, "byte": 75 },
            },
            "text": "println(\"!\")",
          },
        ],
      },
    },
  ])
}

///|
test "match_id" {
  let query =
    #|match a {
    #|  $pat:p => $exp:e
    #|}
  let query = moonbit!().compile!(query)
  let matches = query.search!(
    #|fn main {
    #|  match a {
    #|    _ => 1
    #|  }
    #|  match b {
    #|    _ => 1
    #|  }
    #|}
    ,
  )
  @json.inspect!(matches.collect(), content=[
    {
      "range": {
        "start": { "row": 1, "column": 2, "byte": 12 },
        "end": { "row": 3, "column": 3, "byte": 36 },
      },
      "captures": {
        "p": [
          {
            "range": {
              "start": { "row": 2, "column": 4, "byte": 26 },
              "end": { "row": 2, "column": 5, "byte": 27 },
            },
            "text": "_",
          },
        ],
        "e": [
          {
            "range": {
              "start": { "row": 2, "column": 9, "byte": 31 },
              "end": { "row": 2, "column": 10, "byte": 32 },
            },
            "text": "1",
          },
        ],
      },
    },
  ])
}

///|
test "multiple_patterns" {
  let query =
    #|match a {
    #|  $pat:p1 | $pat:p2 => $exp:e
    #|}
  let query = moonbit!().compile!(query)
  let matches = query.search!(
    #|fn main {
    #|  match a {
    #|    1 | 2 => "number"
    #|  }
    #|}
    ,
  )
  @json.inspect!(matches.collect(), content=[
    {
      "range": {
        "start": { "row": 1, "column": 2, "byte": 12 },
        "end": { "row": 3, "column": 3, "byte": 47 },
      },
      "captures": {
        "p1": [
          {
            "range": {
              "start": { "row": 2, "column": 4, "byte": 26 },
              "end": { "row": 2, "column": 5, "byte": 27 },
            },
            "text": "1",
          },
        ],
        "p2": [
          {
            "range": {
              "start": { "row": 2, "column": 8, "byte": 30 },
              "end": { "row": 2, "column": 9, "byte": 31 },
            },
            "text": "2",
          },
        ],
        "e": [
          {
            "range": {
              "start": { "row": 2, "column": 13, "byte": 35 },
              "end": { "row": 2, "column": 21, "byte": 43 },
            },
            "text": "\"number\"",
          },
        ],
      },
    },
  ])
}

///|
test "guard_condition" {
  let query =
    #|match a {
    #|  $pat:p if $exp:condition => $exp:e
    #|}
  let query = moonbit!().compile!(query)
  let matches = query.search!(
    #|fn main {
    #|  match a {
    #|    x if x > 0 => "positive"
    #|  }
    #|}
    ,
  )
  @json.inspect!(matches.collect(), content=[
    {
      "range": {
        "start": { "row": 1, "column": 2, "byte": 12 },
        "end": { "row": 3, "column": 3, "byte": 54 },
      },
      "captures": {
        "p": [
          {
            "range": {
              "start": { "row": 2, "column": 4, "byte": 26 },
              "end": { "row": 2, "column": 5, "byte": 27 },
            },
            "text": "x",
          },
        ],
        "condition": [
          {
            "range": {
              "start": { "row": 2, "column": 9, "byte": 31 },
              "end": { "row": 2, "column": 14, "byte": 36 },
            },
            "text": "x > 0",
          },
        ],
        "e": [
          {
            "range": {
              "start": { "row": 2, "column": 18, "byte": 40 },
              "end": { "row": 2, "column": 28, "byte": 50 },
            },
            "text": "\"positive\"",
          },
        ],
      },
    },
  ])
}

///|
test "loop_expression" {
  let query =
    #|loop $id:var {
    #|  $pat:p => $exp:e
    #|}
  let query = moonbit!().compile!(query)
  let matches = query.search!(
    #|fn main {
    #|  loop state {
    #|    Empty => 0
    #|    Node(value, next) => value + next
    #|  }
    #|}
    ,
  )
  @json.inspect!(matches.collect(), content=[])
}

///|
test "single_expression" {
  let query =
    #|$exp:a
  let query = moonbit!().compile!(query)
  let matches = query.search!(
    #|fn main {
    #|  println("Hello, world!")
    #|}
    ,
  )
  @json.inspect!(matches.collect(), content=[])
}

///|
test "positional_or_labelled" {
  let query =
    #|f($id:arg ${~}?)
  let query = moonbit!().compile!(query)
  let matches = query.search!(
    #|fn main {
    #|  f(a)
    #|  f(b~)
    #|}
    ,
  )
  @json.inspect!(matches.collect(), content=[
    {
      "range": {
        "start": { "row": 2, "column": 2, "byte": 19 },
        "end": { "row": 2, "column": 7, "byte": 24 },
      },
      "captures": {
        "arg": [
          {
            "range": {
              "start": { "row": 2, "column": 4, "byte": 21 },
              "end": { "row": 2, "column": 5, "byte": 22 },
            },
            "text": "b",
          },
        ],
      },
    },
  ])
}

///|
test "comment" {
  let query =
    #|[1, 2, 3, 4]
  let query = moonbit!().compile!(query)
  let source =
    #|fn main {
    #|  [1, 2, 3, 4]
    #|}
  let matches = query.search!(source)
  @json.inspect!(matches.collect(), content=[
    {
      "range": {
        "start": { "row": 1, "column": 2, "byte": 12 },
        "end": { "row": 1, "column": 14, "byte": 24 },
      },
      "captures": {},
    },
  ])
}

///|
test "replace" {
  let query =
    #|$exp:a + $exp:b
  let query = moonbit!().compile!(query)
  let source =
    #|fn main {
    #|  1 + 2
    #|}
  let matches = query.search!(source)
  @json.inspect!(matches.collect(), content=[
    {
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
  ])
  let replaces = []
  for matched in matches {
    replaces.push(
      matched.replace!(
        #|$b + $a
        ,
      ),
    )
  }
  @json.inspect!(replaces, content=[
    {
      "range": {
        "start": { "row": 1, "column": 2, "byte": 12 },
        "end": { "row": 1, "column": 7, "byte": 17 },
      },
      "text": "2 + 1",
    },
  ])
}
