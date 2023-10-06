func sum(arr: Array[Int], i: Int, acc: Int) -> Int {
  if i < arr.length() { sum(arr, i + 1, acc + arr[i]) } else { acc }
}

let b:Array[Int] = [1, 2, 3, 4, 88]

func init {
  var i = 0
  while i < b.length() {
    print(b[i])
    print('\n')
    i = i + 1
  }
  print(b.length())
  print('\n')
  print(sum(b, 0, 0))
}

