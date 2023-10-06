func init {
  let one = 1
  fn a() {
    b()
  }

  fn b() {
    c()
  }

  fn c() {
    one
  }

  print(a())
}

