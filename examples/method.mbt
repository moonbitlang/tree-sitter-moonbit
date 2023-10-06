func init {
  let (a, b, c, d) = (1, 3.14, 'c', "long_string")
  print(a)
  print("\n")
  print_float(b)
  print("\n")
  print(c)
  print("\n")
  print(d)
  print("\n")
  let f = fn () { print("second_string\n") }
  let g = fn () { print("first_string\n") }
  g()
  f()
}

func init {
  let arr = [2, 0, 2, 3, 0, 3, 2, 8]
  let str = "hello_world!"
  print(arr.get(7))
  print(" = 8\n")
  print(arr.get(0) + arr.length())
  print(" = 10\n")
  print(str.get(arr.get(3)))
  print(" = l\n")
  let f = fn (i) { arr.get(i) }
  let g = fn (i) { str.get(i) }
  print(g(f(4)))
  print(" = h\n")
}

