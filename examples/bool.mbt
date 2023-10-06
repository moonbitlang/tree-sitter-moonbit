let b = true

let f:(Bool) -> Unit = fn(x) {
  match x {
    true => print(1)
    false => print(2)
  }
}

let g:(Bool, Bool) -> Unit = fn(x, y) {
  match (x, y) {
    (true, false) => print(1)
    (false, true) => print(2)
    _ => print(3)
  }
}

func init {
  f(b)
  g(b, b)
  print("\n")
  test_match(true,false)
  test_match(false,true)
  test_match(true,true)
  test_match(false,false)
}

func test_match(x : Bool, y : Bool) {
  match (x, y) {
    (true, false) => print(1)
    (false, true) => print(2)
    (true, true) => print(3)
    (false, false) => print(4)
  }
}

