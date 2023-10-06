func println_f64(self: Float64) {
  print_float(self)
  print("\n")
}

func test_i64(x: Int64, y: Int64) {
  println(-x)
  println(x + y)
  println(x * y)
  println(x - y)
  println(x / y)
  println(x % y)
}

func test_f64(x: Float64, y: Float64) {
  x.println_f64()
  y.println_f64()
  (-x).println_f64()
  (x + y).println_f64()
  (x * y).println_f64()
  (x - y).println_f64()
  (x / y).println_f64()
}

func convert_from_i32(i: Int) {
  println(i)
  println(i.to_int64())
  i.to_float64().println_f64()
}

func convert_from_i64(i: Int64) {
  println(i)
  println(i.to_int())
  i.to_float64().println_f64()
}

func convert_from_f64(i: Float64) {
  i.println_f64()
  print("!!to_int() traps here!!\n")
  // i.to_int().println_i32()
  println(i.to_int64())
}

func compare_i64(i1: Int64, i2: Int64) {
  if (i1 < i2) { print("lt\n") } else { print("not lt\n") }
  if (i1 <= i2) { print("le\n") } else { print("not le\n") }
  if (i1 > i2) { print("gt\n") } else { print("not gt\n") }
  if (i1 >= i2) { print("ge\n") } else { print("not ge\n") }
  if (i1 == i2) { print("eq\n") } else { print("not eq\n") }
}

func init {
  print("==testi64==\n")
  test_i64(2147483648L, 2023L)
  print("==testf64==\n")
  test_f64(20.23 * 9.8, -20.23 / 9.8)
  print("==convert_from_i32==\n")
  convert_from_i32(913)
  print("==convert_from_i64==\n")
  convert_from_i64(-2023L * 2147483647L)
  print("==convert_from_f64==\n")
  convert_from_f64(-202.398 * 2147483647.0)
  print("==compare_i64==\n")
  compare_i64(9223372036854775807L, 223372036854775807L)
}

func init {
  print("==i64_to_string==\n")
  let x = 9223372036854775807L
  let y = -9223372036854775807L
  println(x.to_string() + y.to_string())
}
