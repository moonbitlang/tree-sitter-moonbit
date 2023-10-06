func add(a: Int) -> (Int, Int) -> Int {
  fn(b, c) { a + b + c }
}

func init {
  let add1 = add(111)
  let add2 = add(1111)
  print(add1(3, 4))
  print('\n')
  print(add2(3, 4))
}

