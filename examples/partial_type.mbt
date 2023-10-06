enum t1[X, Y] {
  A (X)
  B (Y)
}

enum t2 {
  A (String)
  B (String)
}

func f1[X] (x: t1[Char, X]) -> Unit {
  match x {
    A(c) => print(c)
    B(_) => print(0)
  }
}

func f2[Y] (x: t1[Y, Char]) -> Unit {
  match x {
    A(_) => print(0)
    B(c) => print(c)
  }
}

func init {
  let x1 = (A('o') : t1[_, _])
  let x2 = (B('k') : t1[_, _])
  f1(x1)
  f2(x2)
}

struct r1[X] {
  a:X
  b:Int
}

struct r2[X] {
  a:String
  b:X
}

func init {
  let f3 = fn(x: r1[_]) { print((x.a: Char)) } // unify _ to Char
  let f4 = fn(x: r2[_]) { print((x.b: Char)) }
  let x3 = ({ a:'o', b:1 } : r1[_])
  let x4 = ({ b:'k', a:"x" } : r2[_])
  f3(x3)
  f4(x4)
}

func get_r1_a[A] (x: r1[A]) -> A {
  x.a
}

// generics
func init {
  let a = ({ a:"ok", b:0 } : r1[_])
  let b = ({ a:'!', b:1 } : r1[_])
  print(get_r1_a(a))
  print(get_r1_a(b))
}

// p<_> gets expanded to p<_,_>
struct p[X, Y] {
  a:X
  b:Y
}

func init {
  let output_int_char = fn(x: p[_]) { print((x.a: Int)); print((x.b: Char)) }
  output_int_char({ a:0, b:'k' })
}

