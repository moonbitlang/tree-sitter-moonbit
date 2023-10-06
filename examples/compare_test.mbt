func hey[T : Compare](x : T, y : T) -> Int {
  x.compare(y)
}

func init {
  print(hey(1, 2))
  print(hey(2, 1))
  print(hey(2, 2))
  print(hey(1.0, 2.0))
  print(hey(2.0, 1.0))
  print(hey(2.0, 2.0))
  print(hey("a", "ab"))
  print(hey("ab", "a"))
  print(hey("ab", "ba"))
}

