pub func all_eq[X : Eq](a : X, b : X, c : X) -> Bool {
  a == b && b == c
}

pub enum X {
  A
  B
}

pub struct T {
  x: X
}

pub struct S {
  a: Int
}

pub func op_equal(self: X, other: X) -> Bool {
  match (self, other) {
    (A, A) | (B, B) => true
    _ => false
  }
}

pub func op_equal(self : T, other : T) -> Bool {
  self.x == other.x
}

pub func op_equal(self : S, other : S) -> Bool {
  self.a == other.a
}

func init {
  let x = X::A
  let t = { x: B }
  if all_eq(x, x, x) && all_eq(t, t, t) {
      print("good")
  }
  let x = 1
  let t = { a: 1 }
  if all_eq(x, x, x) && all_eq(t, t, t) {
      print("good")
  }

}
