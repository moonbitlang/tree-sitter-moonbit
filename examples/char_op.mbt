
func decimal_digit_value(c: Char) -> Int {
  c.to_int() - '0'.to_int()
}

func hexdecimal_digit_value(c: Char) -> Int {
  if '0' <= c && c <= '9' {
    c.to_int() - '0'.to_int()
  } else if 'a' <= c && c <= 'f' {
    c.to_int() - 'a'.to_int() + 10
  } else if 'A' <= c && c <= 'F' {
    c.to_int() - 'A'.to_int() + 10
  } else {
    -1
  }
}

func toggle_case(c: Char) -> Char {
  if 'a' <= c && c <= 'z' {
    Char::from_int(c.to_int() - 'a'.to_int() + 'A'.to_int())
  } else if 'A' <= c && c <= 'Z' {
    Char::from_int(c.to_int() - 'A'.to_int() + 'a'.to_int())
  } else {
    c
  }
}

func init {
  print(decimal_digit_value('0'));
  print(decimal_digit_value('5'));
  print(decimal_digit_value('9'));
  print(hexdecimal_digit_value('1'));
  print(hexdecimal_digit_value('8'));
  print(hexdecimal_digit_value('b'));
  print(hexdecimal_digit_value('F'));
  print(toggle_case('x'))
  print(toggle_case('W'))
  print(toggle_case('0'))
}
