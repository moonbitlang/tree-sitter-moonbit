
enum T {
  A(Int)
  B(Int)
}

func f(t: T) {
  let (A(x) | B(x)) = t
  print(x)
}

func init {
  let (Some(x)) = Option::Some(1)
  let y = 2
  print(x + y)
  f(A(3))
  f(B(4))
}
