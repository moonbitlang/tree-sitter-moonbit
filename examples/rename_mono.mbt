// construct List from Array.
func stream[T](self: Array[T]) -> List[T] {
  fn go(idx: Int) -> List[T] {
    if idx == self.length() { Nil } else { Cons(self[idx], go(idx + 1)) }
  }

  go(0)
}

// length of List
func length[T](self: List[T]) -> Int {
  match self {
    Nil => 0
    Cons(_, xs) => 1 + xs.length()
  }
}

func init {
  let xs = [1,2,3]
  let ys = ["xx","yy"]
  print(xs.stream().length())
  print(ys.stream().length())
}
