func test(b: Bool) {
  let (a, b) = if b { (1, 2) } else { (3, 4) }
  print(a)
  print(b)
}

func init {
  test(true)
  test(false)
}

