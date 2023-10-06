func triple(x: Int) -> Int {
  let triple = fn(x) { return x * 3 }
  triple(x)
}

func init {
  print(triple(16))
}
