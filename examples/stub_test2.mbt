func init {
  print_two_numbers(3, 4)
  print(to_lower('C'))
  let pi = 3.1415926
  pi.print_float()
}

func print_two_numbers(f1: Int, f2: Int) = "spectest" "print_i32_i32"

func to_lower(c: Char) -> Char = "spectest" "to_lower"

func print_float(self: Float64) = "spectest" "print_f64"

