func test(x: Int) {
  if x == 0 {
    print("x is 0")
  } else if x == 1 {
    print("x is 1")
  } else if x == 2 {
    print("x is 2")
  } else {
    print("x is not 0, 1 or 2")
  }
}

func init {
  test(0)
  test(1)
  test(2)
  test(3)
}

