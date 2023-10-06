
func f() -> Int {
  var i = 0
  while i < 10 {
    if true {
      return 1
    }
    i = i + 1
  }
  0
}

func init {
  print(f())
}
