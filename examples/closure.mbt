// normal closure
func f() -> (() -> Float64) {
  let x = 20.23
  let y = "Monday"
  let z = 9.11
  fn f1() {
    print_float(x)
    print(y)
    print_float(z)
    print("\n")
    x - z
  }
  f1
}

func init {
  print("\n==normal closure==\n")
  let f1 = f()
  print_float(f1())
}

// well-known closure with more than one free variables
func g() {
  let x = 20.23
  let y = "Monday"
  let z = 9.11
  fn g1() {
    print_float(x)
    print(y)
    print_float(z)
    print("\n")
  }
  g1()
  print("\n")
}
func init {
  print("\n==well-known closure==\n")
  g()
}

// well-known closure with single variables
func h() {
  let x = 20.23
  fn h1() {
    print_float(x)
  }
  h1()
  print("\n")
}
func init {
  print("\n==well-known closure single capture==\n")
  h()
}
