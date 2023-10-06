func add(self: Int, rhs: Int) -> Int {
  self + rhs
}

func add_float(self: Float64, rhs: Float64) -> Float64 {
  self + rhs
}

func init {
  print(5.add(10))
  print_float(5.0.add_float(1.5))
}

