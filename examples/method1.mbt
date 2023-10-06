enum t {
  A (Int)
  B (Char)
}

struct r[A, B] {
  foo:(A) -> B
  bar:t
}

func to_string(self: t) -> String {
  match self {
    A(i) => i.to_string()
    B(c) => c.to_string()
  }
}

func to_string[A : Show, B : Show] (self: r[A, B]) -> String {
  "{ foo; bar = " + self.bar.to_string() + "}"
}

func init {
  let x : t = A(1)
  print(x)
  let y : t = B('c')
  print(y)
  let z = { foo:fn(x: Int) { x }, bar:y }
  print(z)
}

