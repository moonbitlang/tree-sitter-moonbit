func iter[T](self: List[T], f: (T) -> Unit) {
  fn go(l: List[T]) {
    match l {
      Nil => ()
      Cons(x, xs) => { f(x); go(xs) }
    }
  }
  go(self)
}

func to_list[T](self: Array[T]) -> List[T] {
  fn go(i: Int) -> List[T] {
    if i == self.length() { Nil } else { Cons(self[i], go(i+1)) }
  }
  go(0)
}

func init {
  [1, 2, 3, 4, 5].to_list().iter(fn(x) {
    print(x)
    print("\n")
  })
}
