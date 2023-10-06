let test:(Bool) -> Unit = fn(b) {
  if b { print("ok\n") } else { print("not ok\n") }
}

struct t1 {
  x:Int
  y:Int
}

struct t2 {
  x:Int
  y:Int
  z:Int
}

func init {
  let a = { x:1, y:2 }
  let b = { x:3, y:4, z:5 }
  test(a.x == 1)
  test(a.y == 2)
  test(b.x == 3)
  test(b.y == 4)
  test(b.z == 5)
}

func t1_of_t2(x: t2) -> t1 {
  let x = match x {
    {x:a, y:b, z:c} => { x:a, y:b }
  }
  x
}

func init {
  let x = { x:3, y:4, z:5 }
  let y = t1_of_t2(x)
  test(y.x == 3)
  test(y.y == 4)
}

