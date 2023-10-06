// constructor
enum t1 {
  A (Char)
  B (Int)
}

enum t2 {
  A (Int)
  B (Char)
}

func f1(x: t1) -> Unit {
  match x {
    A(c) => print(c)
    B(i) => print(i)
  }
}

func f2(x: t2) -> Unit {
  match x {
    A(i) => print(i)
    B(c) => print(c)
  }
}

func init {
  f1(A('1'))
  f1(B(2))
  f2(A(3))
  f2(B('4'))
}

// record field
struct r1 {
  a:t1
  b:t2
}

struct r2 {
  a:t2
  b:t1
}

func f3(x: r1) -> Unit {
  match x {
    {a:A(c), b:A(i)} => { print(c); print(i) }
    {a:A(c), b:B(d)} => { print(c); print(d) }
    {a:B(i), b:A(j)} => { print(i); print(j) }
    {a:B(i), b:B(c)} => { print(i); print(c) }
  }
}

func f4(x: r2) -> Unit {
  match x {
    {a:A(i), b:A(c)} => { print(i); print(c) }
    {a:A(i), b:B(j)} => { print(i); print(j) }
    {a:B(c), b:A(d)} => { print(c); print(d) }
    {a:B(c), b:B(i)} => { print(c); print(i) }
  }
}

func init {
  f3({ a:B(5), b:B('6') })
  f4({ a:B('7'), b:B(8) })
}

// let
func init {
  let x1 = (A('9') : t1)
  let x2 : t2 = A(1)
  let x3 = ((B(0) : t1) : t1)
  f1(x1)
  f2(x2)
  f1(x3)
  let x4 : r1 = { a:A('J'), b:B('Q') }
  let x5 = ({ a:B('K'), b:A('A') } : r2)
  f3(x4)
  f4(x5)
}

