func hello(x: Int) -> Int {
  fn hey(y: Int) {
    y + x
  }

  hey(3)
}

func init {
  print(hello(2))
}

