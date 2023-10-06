func down_to_0(self: Int, f: (Int) -> Unit) {
  if self >= 0 {
    f(self)
    (self-1).down_to_0(f)
  }
}

func init {
  10.down_to_0(fn(x) {
    print(x)
    print("\n")
  })
}
