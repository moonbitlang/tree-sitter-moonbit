func init {
  let xs = ["", "1", "12", "123", "1234"]
  let ys = ["", "a", "ab", "abc", "abcd"]
  var i = 0
  while i < xs.length() {
    var j = 0
    while j < ys.length() {
      print(xs[i] + ys[j])
      print("\n")
      j = j + 1
    }
    i = i + 1
  }
  var sum = ""
  i = 0
  while i < ys.length() {
    sum = sum + ys[i]
    i = i + 1
  }
  print(sum)
  print("\n")
}

