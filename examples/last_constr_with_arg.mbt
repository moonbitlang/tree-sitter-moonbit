
enum MyPair[T, U] {
  MyPair(T, U)
}

func fst[T, U](self: MyPair[T, U]) -> T {
  let (MyPair(t, _)) = self
  t
}

func snd[T, U](self: MyPair[T, U]) -> U {
  let (MyPair(_, u)) = self
  u
}

func get_opt[X](opt: Option[X], default: X) -> X {
  match opt {
    None => default
    Some(x) => x
  }
}

func init {
  let p = MyPair::MyPair(1, MyPair::MyPair("2", 3))
  print(p.fst())
  print(p.snd().fst())
  print(p.snd().snd())
  print(get_opt(None, 0))
  print(get_opt(Some(5), 0))
}
