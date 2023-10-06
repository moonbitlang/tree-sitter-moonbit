func init {
  var x = 0
  var y = 1
  var i = 0
  print("Fib: ")
  while i < 20 {
    let xy = x + y
    print("\(x) + \(y) = \(xy)\n")
    x = y
    y = xy
    i = i + 1
  }
}

