enum h[X, Y] {
  A
  D
  E (X)
  F (Y)
}

let h:((Int, h[Bool, Bool])) -> Bool = fn(a) {
  match a {
    (1, D) => true
    (_, E(x)) => x
    (_, F(c)) => c
  }
}

