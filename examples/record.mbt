let test:(Bool) -> Unit = fn(b) {
  if b { print("ok\n") } else { print("not ok\n") }
}

struct r1 {
  x:Int
  y:Bool
}

struct r2[A, B] {
  a:A
  b:B
}

let p1:r1 = { x:3, y:true }

let p2:r2[Char, Char] = { a:'a', b:'b' }

let p3:r2[r1, r2[Char, Char]] = { a:p1, b:p2 }

let p4:r2[Int, Int] = { b:2, a:1 }

func init {
  test(p1.x == 3)
  test(p2.a == 'a')
  test(p2.b == 'b')
  test(p3.a.x == 3)
  test(p3.b.a == 'a')
  test(p4.b == 2)
  test(p4.a == 1)
}

// mutation
struct r3 {
  mut x1:Int
  x2:Bool
}

let p5:r3 = { x1:3, x2:true }

func init {
  test(p5.x1 == 3)
  p5.x1 = 4
  test(p5.x1 == 4)
}

// pattern matching
func init {
  match p1 {
    {x:v1, y:v2} => { test(v1 == 3); test(v2 == true) }
    _ => print("not ok\n")
  }
}

func init {
  match p2 {
    {b:c1, a:c2} => { test(c1 == 'b'); test(c2 == 'a') }
    _ => print("not ok\n")
  }
}

// generalization
struct r4[A] {
  y1:A
  y2:Int
}

func get_y1[A] (p: r4[A]) -> A {
  p.y1
}

func init {
  let p7 = { y1:Option::None, y2:1 }
  let p8 = { y1:p7, y2:2 }
  match get_y1(get_y1(p8)) {
    Some(_) => print("not ok\n")
    None => print("ok\n")
  }
}

// value restriction
struct r5[A] {
  mut z1:A
  z2:Int
}

func init {
  let p9 = { z1:Option::None, z2:3 }
  ()
}

// more about generalization
struct r6[A, B, C] {
  w1:A
  w2:Option[B]
  w3:r2[C, C]
}
// more pattern matching

func init {
  let p11 = { w1:List::Nil, w2:Option::Some(1), w3:{ a:"xxx", b:"yyy" } }
  match p11 {
    {w1:v1, w2:None, w3:_} => print("not ok\n")
    {w1:v1, w2:Some(0), w3:{a:_, b:_}} => print("not ok\n")
    {w1:_, w2:Some(1), w3:{a:v1, b:v2}} => {
      print(v1)
      print(v2)
      print("...ok\n")
    }
    _ => print("not ok\n")
  }
}

// more about polymorphism
struct r7[A, B] {
  ff:(A, B) -> A
  gg:Int
}

func init {
  let p14 = { ff:fn(x, y) { x }, gg:1 }
  test((p14.ff)(1, 'c') == 1)
}

// record disambiguate
struct r8 {
  i:Int
  j:Bool
}

struct r9 {
  i:Bool
  j:Int
}

func init {
  let x1 = ({ i:1, j:true } : r8)
  let x2 = ({ i:true, j:2 } : r9)
  let f1 = fn(x: r8) { if x.j && x.i == 1 { print("ok\n") } }
  let f2 = fn(x: r9) { if x.i && x.j == 2 { print("ok\n") } }
  f1(x1)
  f2(x2)
}

// record disambiguate on mutation
struct r10 {
  mut i:Int
  j:Bool
}

struct r11 {
  mut i:Bool
  j:Int
}

func init {
  let x1 = ({ i:1, j:true } : r10)
  let x2 = ({ i:false, j:2 } : r11)
  let f1 = fn(x: r10, y: r11) { x.i = x.i + y.j; y.i = x.j || y.i }
  f1(x1, x2)
  if x1.j && x1.i == 3 { print("ok\n") }
  if x2.i && x2.j == 2 { print("ok\n") }
  ()
}

