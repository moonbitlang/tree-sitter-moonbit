///|
#deprecated("Use fib2 instead")
// <- attribute.builtin
#coverage.skip
// <- attribute.builtin
fn fib(n : Int) -> Int {
  -1
}

///|
#attribute
// <- attribute
fn fib2(n : Int) -> Int {
  -1
}
