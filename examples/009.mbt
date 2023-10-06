let a:Array[Int] = Array::make(3, 2)

func init {
  print(a.length())
}

let d = 4

func init {
  print('\n')
  a[1] = 33
  print(a[1])
  print('\n')
  print((a[2] + d + a[1]))
  print('\n')
  print(a.length())
}

