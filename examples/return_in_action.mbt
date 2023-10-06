
func ignore(x: Int) {}

func f(x: Bool) -> Int {
  ignore (match x {
    true => { return 0 }
    false => 1
  })
  2
}

func init {
  print(f(true))
  print(f(false))
}
