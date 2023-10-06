func println_i32(self: Int) {
  println(self)
}

func println_i64(self: Int64) {
  print_int64(self)
  print("\n")
}

func init {
  println_i32(2023)
  99.println_i32()

  2147483648910L.println_i64()
  println_i64(21474836487654L)
}

func match_i64(i: Int64) {
  match i {
   9223372036854775807L => { print("MAX\n") }
   9223372036854775806L => { print("MAX-1\n") }
   _ => { i.println_i64() }
  }
}

func init {
  let x = 9223372036854775807L
  let y = -9223372036854775808L
  println_i64(x)
  println_i64(y)
  match_i64(x)
  match_i64(911L)
}
