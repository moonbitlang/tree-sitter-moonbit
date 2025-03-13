fn fib(n : Int) -> Int {
// <- keyword.function
// ^^^ function
  //  ^ punctuation.bracket
  //   ^ variable.parameter
  //       ^^^ type.builtin
  //          ^ punctuation.bracket
  //            ^^ operator
  //               ^^^ type.builtin
  //                   ^ punctuation.bracket
  match n {
  // <- keyword.conditional
    //  ^ variable
    //    ^ punctuation.bracket
    0 => 1
    // <- number
    //^^ operator
    //   ^ number
    1 => 1
    n => fib(n - 1) + fib(n - 2)
    //         ^ operator
    //              ^ operator
    //                      ^ operator
  }
}
// <- punctuation.bracket
