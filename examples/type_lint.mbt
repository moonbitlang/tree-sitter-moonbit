
func f[X](x: X) -> X {
  fn g(x) {}
  x
}

func init {
  print(f(0))
}


enum T[X] {
  A
  B(X)
}

func g[_X]() {} 

func init {
  g()
}
