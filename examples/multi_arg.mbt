enum lst {
  Empty
  Cons (Int, lst)
}

func init {
  let h : lst = Cons(1, Empty)
  let Cons(x, Empty) = h
  print(x)
  match h {
    Empty => ()
    Cons(x, _) => print(x)
  }
  ()
}

