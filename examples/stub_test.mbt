let a:Int = {print(3); 0}

func hello() {
  ()
}

// print should be generated before hello
func print_i32(self: Int) = "spectest" "print_i32"

func init {
  3.print_i32()
}

func init {
  let h = print_i32
  h(2)
  print_two_numbers(3, 4)
  print('c')
  print(to_lower('C'))
}

func print_two_numbers(f1: Int, f2: Int) = "spectest" "print_i32_i32"

func to_lower(c: Char) -> Char = "spectest" "to_lower"

