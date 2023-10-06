struct t {
  mut value:Int
}

func sum(x: Array[Int]) -> Int {
  let u = { value:0, }
  var i = 0
  while i < x.length() {
    u.value = u.value + x[i]
    i = i + 1
  }
  u.value
}

func init {
  print(sum([1, 2, 3, 4, 5]))
}

