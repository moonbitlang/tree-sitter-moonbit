func f(x: String) -> Int {
  match x {
    "ok11" => 1
    "ok2" => 2
    "ok3" => 3
    _ => 4
  }
}

func init {
  print(f("ok11"))
  print(f("ok2"))
  print(f("ok3"))
  print(f("ok33"))
}

