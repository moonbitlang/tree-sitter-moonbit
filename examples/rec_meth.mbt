enum lst[X] {
  MNil
  MCons (X, lst[X])
}

func length[X] (self: lst[X]) -> Int {
  match self {
    MNil => 0
    MCons(_, xs) => 1 + xs.length()
  }
}

func to_lst[X] (self: List[X]) -> lst[X] {
  match self {
    Nil => MNil
    Cons(x, xs) => MCons(x, xs.to_lst())
  }
}

func iter[X] (self: lst[X], f: (X) -> Unit) -> Unit {
  match self {
    MNil => ()
    MCons(x, xs) => { f(x); xs.iter(f) }
  }
}

func map[X, Y] (self: lst[X], f: (X) -> Y) -> lst[Y] {
  match self {
    MNil => MNil
    MCons(x, xs) => MCons(f(x), xs.map(f))
  }
}

func init {
  let xs : List[_] = Cons(1, Cons(2, Cons(3, Nil)))
  let len = xs.to_lst().length()
  print("length = ")
  print(len)
  print("\n")
  xs.to_lst().map(fn(x) { x * 3 }).iter(fn(x) { print(x) })
}

