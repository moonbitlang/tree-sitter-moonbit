// TODO: support Lstringswitch
func init {
  let x = 'c'
  match x {
    'a' => print('a')
    'b' => print('b')
    'c' => print('c')
    _ => print('d')
  }
  let x = 1.1
  match x {
    0.1 => print('a')
    1.1 => print('b')
    1.11 => print('c')
    _ => print('d')
  }
  let x = "ss"
  match x {
    "s" => print(1)
    "ss" => print(2)
    "sss" => print(3)
    _ => print(4)
  }
}

