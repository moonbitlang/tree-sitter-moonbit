//!build:-disable-gc
let output_string:(String) -> Unit = fn(n) {
  var i = 0
  while i < n.length() {
    print(n[i])
    i = i + 1
  }
}

func apply[X, Y] (f: (X) -> Y, x: X) -> Y {
  f(x)
}

func fib(n: Int) -> Int {
  if n < 2 { n } else { fic(n - 1) + fic(n - 2) }
}

func fic(n: Int) -> Int {
  if n < 2 { n } else { fib(n - 1) + fib(n - 2) }
}

let fib2:((Int) -> Int) -> (Int) -> Int = fn(f) {
  fn(n) { if n < 2 { n } else { f(n - 1) + f(n - 2) } }
}

func z[W, X, Y, Z] (f: ((X) -> Y) -> Z) -> W {
  (fn(g) { obj_magic(g)(g) }) (fn(x) { f(fn(v) { obj_magic(x)(x)(v) }) })
}

func init {
  print("Simple:\n")
  var i = 0
  while i <= 10 {
    print(apply(fib, i))
    print('\n')
    i = i + 1
  }
  print("Z combinator:\n")
  i = 0
  while i <= 10 {
    print((apply(z(fib2), i): Int))
    print('\n')
    i = i + 1
  }
}

