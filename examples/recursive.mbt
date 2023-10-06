func hello(x: Int) -> Int {
  x
}

func even(x: Int) -> Bool {
  match x {
    0 => true
    1 => false
    _ => odd(x - 1)
  }
}

func add(x: Int, y: Int) -> Int {
  x + y + 100
}

func odd(x: Int) -> Bool {
  match x {
    0 => false
    1 => true
    _ => even(x - 1)
  }
}

