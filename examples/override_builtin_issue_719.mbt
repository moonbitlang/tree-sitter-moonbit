// Issue #719

let data = "hello world"

func printTest() {
  print(data)
}

// overriding builtin sub
func op_sub(self: Int, other: Int) -> Int {
  self + other
}

enum lst[X] {
  Nil
  Cons (X, lst[X])
}

func length[X] (self: lst[X]) -> Int {
  match self {
    Nil => 0
    Cons(_, xs) => 1 + length(xs) // no ambiguity here
  }
}

func init {
  printTest()
  print(5 - 3) // print 8
  let xs = lst::Cons(1, Cons(2, Nil))
  print(length(xs)) // print 2
  let ys = [1,2,3]
  print(ys.length()) // no ambiguity here
}
