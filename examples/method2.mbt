// copy of rec_meth.rael but some methods are called as functions
enum Lst[X] {
  MNil
  MCons (X, Lst[X])
}

func length[X] (self: Lst[X]) -> Int {
  match self {
    MNil => 0
    MCons(_, xs) => 1 + xs.length()
  }
}

func to_lst[X] (self: List[X]) -> Lst[X] {
  match self {
    Nil => MNil
    Cons(x, xs) => MCons(x, to_lst(xs))
  }
}

func iter[X] (self: Lst[X], f: (X) -> Unit) -> Unit {
  match self {
    MNil => ()
    MCons(x, xs) => { f(x); iter(xs, f) }
  }
}

func map[X, Y] (self: Lst[X], f: (X) -> Y) -> Lst[Y] {
  match self {
    MNil => MNil
    MCons(x, xs) => MCons(f(x), map(xs, f))
  }
}

func init {
  let xs : List[_] = Cons(1, Cons(2, Cons(3, Nil)))
  let f = to_lst
  let len = f(xs).length()
  print("length = ")
  print(len)
  print("\n")
  let g = fn(xs: Lst[_]) { xs.iter(fn(x: Int) { print(x) }) }
  g(to_lst(xs).map(fn(x) { x * 3 }))
}

