func id[A] (x: A) -> A {
  (x : A)
}

func map[A, B] (xs: List[A], f: (A) -> B) -> List[B] {
  fn go(xs: List[A]) -> List[B] {
    match xs {
      Nil => Nil
      Cons(x, rest) => Cons(f(x), go(rest))
    }
  }

  go(xs)
}

func iter[A] (xs: List[A], f: (A) -> Unit) -> Unit {
  fn go(xs: List[A]) -> Unit {
    match xs {
      Nil => ()
      Cons(x, rest) => { f(x); go(rest) }
    }
  }

  go(xs)
}

func init {
  iter(map(Cons(1, Cons(2, Cons(3, Nil))), fn(x) { x + 1 }), fn (x) { print(x) })
}

