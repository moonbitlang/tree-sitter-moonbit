///|
test {
  let buf = @buffer.new()
  (buf as &Logger).write_string("a")
  //   ^^ keyword
  let opt_int = Some(3)
  guard opt_int is Some(3)
  //            ^^ keyword
  if opt_int is None {
    //       ^^ keyword
    println("impossible")
  }
}
