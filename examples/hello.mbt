func iter(l: List[Int], f: (Int) -> Unit) -> Unit {
  match l {
    Nil => ()
    Cons(x, xs) => { f(x); iter(xs, f) }
  }
}

func map(l: List[Int], f: (Int) -> Int) -> List[Int] {
  match l {
    Nil => Nil
    Cons(x, xs) => Cons(f(x), map(xs, f))
  }
}

func hello(a: Int, b: Int) -> Int {
  a + b
}

func init {
  print(hello(1, 2))
  let data : List[Int] = Cons(1, Cons(2, Cons(3, Cons(4, Nil))))
  iter(map(data, fn(x) { x + 1 }), (fn (x) { print(x) }))
}

