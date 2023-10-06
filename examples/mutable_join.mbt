func test() -> Int {
  var f = fn(x) { x + 1 }
  f(2)
}

func test2() -> Int {
  var f = fn(x) { x + 1 }
  f = fn(x) { x + 10 }
  f(2)
}

func init {
  print(test())
  print(test2()) // expect to  print 12
}

