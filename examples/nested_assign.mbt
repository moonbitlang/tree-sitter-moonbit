struct h {
  x:u
}

struct u {
  mut x:x
}

struct x {
  mut body:Int
}

func hello(x: h) {
  x.x.x.body = 3
}

func init {
  fn test(x : Array[Array[Array[Array[Int]]]]) {
    x[0][0][1][2] = 2
  }

  let x = [[[[1, 2, 3], [3, 4, 5]]]]
  test(x)
  print(x[0][0][1][2])
}

