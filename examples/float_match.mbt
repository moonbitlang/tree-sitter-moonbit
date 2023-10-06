enum T {
  A(Float64, Int)
  B(Float64)
  C(Char)
}

pub func g(x: T) {
  match x {
    A(f, i) => { print_float(f); print(i) }
    B(f) => print_float(f)
    C(c) => print(c)
  }
}

func init {
  g(A(8.28, 2023))
}
