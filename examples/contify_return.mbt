func triple(x: Int) -> Int {
  let s = {
    let double = fn(x) { return x * 2 }
    double(x)
  }
  s + x
}

func init {
  print(triple(16))
}
