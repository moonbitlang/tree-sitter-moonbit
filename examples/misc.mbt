//!build:-disable-gc
func listAdd(fs: List[Int], gs: List[Int]) -> List[Int] {
  match (fs, gs) {
    (Nil, fs) => fs
    (fs, Nil) => fs
    (Cons(f, fs), Cons(g, gs)) => Cons(f + g, listAdd(fs, gs))
  }
}

func listMul(fs: List[Int], gs: List[Int]) -> List[Int] {
  match (fs, gs) {
    (Nil, _) | (_, Nil) => Nil
    (Cons(f, fs), Cons(g, gs)) =>
      Cons(f * g, listAdd(listMul(Cons(f, Nil), gs), listMul(fs, Cons(g, gs))))
  }
}

func listPow(x: List[Int], n: Int) -> List[Int] {
  if n <= 1 { x } else { listMul(listPow(x, n - 1), x) }
}

func pr(a: List[Int]) -> Unit {
  match a {
    Nil => ()
    Cons(x, xs) => { print(x); print(' '); pr(xs) }
  }
}

func init {
  var i = 1
  while i <= 6 {
    pr(listPow(Cons(1, Cons(1, Nil)), i))
    print('\n')
    i = i + 1
  }
}

func init {
  fn fib0(n: Int) {
    if n < 2 { n } else { fib0(n - 1) + fib0(n - 2) }
  }

  print(fib0(6))
  fn fib(n: Int) -> Int {
    if n < 2 { n } else { fic(n - 1) + fic(n - 2) }
  }

  fn fic(n: Int) -> Int {
    if n < 2 { n } else { fib(n - 1) + fib(n - 2) }
  }

  print(fib(7))
  var i = 0
  while i <= 10 {
    print(i)
    print(' ')
    i = i + 1
  }
}

func init {
  let (lo, hi) = (3, 7)
  var i = lo
  while i <= hi {
    print(i + lo + hi)
    print(' ')
    i = i + 1
  }
}

func init {
  match (2, 1) {
    (1, 2) => print(1)
    (_, _) => print(2)
  }
}

enum h1 {
  A (Int)
  B (Int)
}

func init {
  let f = fn(x: (h1, h1)) {
    match x {
      (A(x), A(y)) => print(x + y)
      (A(x), B(y)) => print(y - x)
      (B(x), A(y)) => print(3)
      (B(x), B(y)) => print(4)
    }
  }
  f((A(3), A(4)))
  print(' ')
  f((A(3), B(4)))
}

enum h2[X, Y] {
  A1
  D
  E (X)
  F (Y)
}

func init {
  let h = fn(a) {
    match a {
      (1, h2::D) => { print(1); print('d') }
      (_, E((x:Int))) => { print(x); print('e') }
      (_, F((c:Char))) => { print(c); print('f') }
    }
  }
  h((1, D))
  h((0, E(2)))
  h((3, F('x')))
}

func init {
  let k1 = fn(a, b) { a }
  let k2 = fn(a, b) { b }
  print(k1(3, 4) + k2(5, 6))
}

func init {
  print(1)
}

func init {
  let (a, b) = (3, 4)
  print(a + b)
}

