
func f1(arr: Array[Bool]) -> Int {
  match arr {
    [] => 1
    [true] => 2
    [_, false] => 3
    [false] => 4
    [true, _] => 5
    _ => 6
  }
}

func init {
  print(f1([]))
  print(f1([true ]))
  print(f1([false]))
  print(f1([true , true ]))
  print(f1([true , false]))
  print(f1([false, true ]))
  print(f1([false, false]))
  print(f1([true, true, true]))
  print("\n===\n")
}
