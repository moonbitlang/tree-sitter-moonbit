
func f(msg: String) {
  if msg.length() < 10 { print("\(msg)\n") } else { abort(msg) }
}

func init {
  f("12345")
  f("message too long")
}
