pub func test(b:Bool) {
  let (x, y) = if b {
    (1, 2)
  } else {
    (3, 4)
  }
  print(x)
  print(y)
}

