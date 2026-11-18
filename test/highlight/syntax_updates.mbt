fn main {
  guard! value is Some(item)
  // <- keyword
  errdefer cleanup()
  // <- keyword
  let items = [|1, 2|]
  //          ^^ punctuation.bracket
  let empty = [||]
  //            ^^ punctuation.bracket
  let bytes = b"value=\{value}"
  //          ^^^^^^^^ string
  let regex = reb"[0-9]+"
  //          ^^^^^^^^^^^ string.regexp
  lexmatch input with first {
  //                  ^^^^^ keyword
    _ => ()
  }
  lexscan scanner with longest {
  //                   ^^^^^^^ keyword
    re"^x" => ()
    _ => ()
  }
}

async fn cleanup() -> Unit noraise + nocancel { () }
  //                                 ^^^^^^^^ keyword.exception
