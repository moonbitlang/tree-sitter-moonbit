
func f() -> Int {
  print("f()\n")
  0
}

func init {
  match f() {
    _ => print("done\n")
  }
}
