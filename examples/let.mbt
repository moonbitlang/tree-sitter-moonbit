//!build:-disable-gc
let output_string:(String) -> Unit = fn(n) {
  var i = 0
  while i < n.length() {
    print(n[i])
    i = i + 1
  }
}

func even(n: Int) -> Unit {
  if n == 0 { print("yes\n") } else { odd(n - 1) }
}

func odd(n: Int) -> Unit {
  if n == 0 { print("no\n") } else { even(n - 1) }
}

func init {
  odd(7)
  odd(6)
  even(6)
  even(7)
}

enum t {
  A
  B (Int)
  C (Char)
}

func init {
  let B(x) = t::B(3)
  print(x)
}

// let () =
// let B(3) = C('c') ;
func init {
  let a : t = B(7)
  let b : t = C('e')
  let B(x) = a
  let C(y) = b
  print(x)
  print(y)
}

// fn f<X, Y> (a: X, b: Y): Unit { print(3) }
func init {
  // value restrict
  let f = (fn(a) { Option::None }) (3)
  // value restrict
  let f = (fn(x) { x }) (fn(x) { x })
  let f = fn(x) { (fn(x) { x }) (fn(x) { x })(x) }
  fn f(x) {
    (fn(x) { x }) (fn(x) { x })(x)
  }

  let f = fn() { Option::None }
  let x = f()
  match x {
    Some(a) => print("some!\n")
    None => print("none!\n")
  }
}

// constructors
let f1:(Int) -> t = fn(x) { B(x) }

let f2:(Char) -> t = fn(x) { C(x) }

// let f = fn (x, xs) -> (::) (x, xs)
// let f = (::)

let s1 = "yes\n"

let s2 = "no\n"

func even1(n: Int) -> Unit {
  if n == 0 { print(s1) } else { odd(n - 1) }
}

func odd1(n: Int) -> Unit {
  if n == 0 { print(s2) } else { even(n - 1) }
}

func init {
  odd1(7)
  even1(7)
}

