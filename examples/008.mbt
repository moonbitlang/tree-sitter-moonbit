func fib(n: Int) -> Int {
  match n {
    0 | 1 => 1
    _ => fib(n - 1) + fib(n - 2)
  }
}

func init {
  print(fib(10))
}

