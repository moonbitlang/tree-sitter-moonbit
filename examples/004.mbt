enum h[M, N] {
  A
  D
  E (M)
  F (N)
}

func init {
  let f = fn(x) {
    match x {
      h::A => print('a')
      E((x:Int)) => print(x)
      F(c) => print('f')
    }
  }
  f(E(1))
  f(A)
}

