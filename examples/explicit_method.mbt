
struct T {
  x: Int
}

func T::add(self: T, other: T) -> T {
  { x: self.x + other.x }
}

func init {
  print(T::add({ x: 1 }, { x: 2 }).x)
  print("\n")
}


func T::default() -> T {
  { x: Int::default() }
}

func two_default[X: Default]() -> (X, X) {
  (X::default(), X::default())
}

func init {
  let ((x: T), y) = two_default()
  print(x.x)
  print(y.x)
  print("\n")
}
