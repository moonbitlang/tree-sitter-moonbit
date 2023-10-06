
func print_bool(b: Bool) {
  if b { print("O") } else { print("X") }
}

func test_int_relation(f: (Int, Int) -> Bool) {
  print_bool(f(1, 2))
  print_bool(f(1, 1))
  print_bool(f(2, 1))
  print("\n")
}

func test_int_predicate(f: (Int) -> Bool) {
  print_bool(f(-1))
  print_bool(f(0))
  print_bool(f(1))
  print("\n")
}


func init {
  test_int_relation(fn (x, y) { x == y })
  test_int_relation(fn (x, y) { x < y })
  test_int_relation(fn (x, y) { x <= y })
  test_int_relation(fn (x, y) { x > y })
  test_int_relation(fn (x, y) { x >= y })

  test_int_predicate(fn (x) { x.is_pos() })
  test_int_predicate(fn (x) { x.is_neg() })
  test_int_predicate(fn (x) { x.is_non_pos() })
  test_int_predicate(fn (x) { x.is_non_neg() })

  print_bool(1.lsl(4) - 1 == 15)
  print_bool(3.lsl(1) == 6)
  print_bool(16.lsr(4) == 1)
  print_bool(15.lsr(2) == 3)
  print_bool(10000.asr(2) == 2500)
  print_bool((-10000).asr(3) == -1250)
  print("\n")
}
