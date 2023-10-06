
func init {
  print(1 + 2 * 3 + 4 - 5)
  if 2 * 2 + 3 == 9 / 2 + 10 / 3 {
    print("true")
  } else {
    print("false")
  }
  match 1 {
    0 => print(0)
    1 => print(1)
    x => print(x)
  }
  match 2 {
    0 => print(0)
    1 => print(1)
    x => print(x)
  }
  match true {
    true  => print("true")
    false => print("false")
  }
  match Option::Some(1) {
    None => print(0)
    Some(x) => print(x + 1)
  }
}
