func sum(x: Array[Int]) -> Int {
  var u = 0
  var i = 0
  while i < x.length() {
    u = u + x[i]
    i = i + 1
  }
  u
}

func init {
  print(sum([1, 2, 3, 4, 5]))
}

func iter[X] (xs: List[X], f: (X) -> Unit) -> Unit {
  match xs {
    Nil => ()
    Cons(x, rest) => { f(x); iter(rest, f) }
  }
}

func sum_list(xs: List[Int]) -> Int {
  var total = 0
  iter(xs, fn(x) { total = total + x })
  total
}

func init {
  print(sum_list(Cons(1, Cons(2, Cons(3, Cons(4, Cons(5, Nil)))))))
}

func rev[X] (xs: List[X]) -> List[X] {
  var acc : List[_] = Nil
  iter(xs, fn(x) { acc = Cons(x, acc) })
  acc
}

func init {
  iter(rev(Cons(1, Cons(2, Cons(3, Nil)))), fn (x) { print(x) })
}

func init {
  var id = fn(x) { x }
  id = fn(x: Int) { x + 1 }
  if id(0) == 1 { print("\nok\n") } else { print("\nnot ok\n") }
  id = fn(x) { x + 2 }
  if id(0) == 2 { print("ok\n") } else { print("not ok\n") }
}

func init {
  var x = 3
  match x {
    3 => print("ok")
    _ => print("not ok")
  }
}

// toplevel mutable
let str_buf : Ref[() -> Unit] = { val: fn() { print("\n") } }
func replace_str(s: String) -> Unit {
  (str_buf.val)()
  str_buf.val = fn() { print(s) }
}

func flush_str() -> Unit {
  (str_buf.val)()
}

func init {
  replace_str("1.ok!\n")
  replace_str("2.ok!\n")
  flush_str()
}
