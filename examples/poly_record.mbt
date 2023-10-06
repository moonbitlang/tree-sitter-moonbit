let test:(Bool) -> Unit = fn(b) {
  if b { print("ok\n") } else { print("not ok\n") }
}

struct r[A] {
  id:(A) -> A
}

func init {
  let p1 : r[_] = { id:fn(x) { x }, }
  let p2 : r[_] = { id:fn(x) { x }, }
  test((p1.id)(1) == 1)
  test((p2.id)('c') == 'c')
}

