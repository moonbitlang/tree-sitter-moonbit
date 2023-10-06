func f(a: Int) -> Int {
  var ma = a
  while ma > 10 {
    if ma > 100 { return ma }
    ma = ma + 1
  }
  return a
}

func g(a: Int) {
  if a == 1 { print("value is one\n"); return  }
  if a == 2 { print("value is two\n"); return  }
  print("value is neither one nor two\n")
}

func h(a: Int) {
  if a == 1 { return g(a) }
  return print(f(a))
}

func init {
  print(f(10))
  print(f(11))
  print("\n")
  g(1)
  g(2)
  g(3)
  print("\n")
  h(1)
  h(2)
}

