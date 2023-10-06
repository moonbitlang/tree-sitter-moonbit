func init {
  let a = 1
  let b = 2
  fn o(x) {
    print(a + b)
  }

  let c = a + b
  let d = c
  o(a + b + c)
}

