func init {
  print(f(100))
}

func f(x: Int) -> Int {
  fn aux(n: Int) {
    if n == 0 {
      0
    } else {
      if n > 10000 {
        return -1
      }
      aux(n - 1)
    }
  }
  aux(x)
}

