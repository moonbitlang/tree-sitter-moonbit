let check:(Bool) -> Unit = fn(b) { print(if b { '.' } else { 'x' }) }

func apply[X, Y] (f: (X) -> Y, x: X) -> Y {
  f(x)
}

let add:(Int, Int) -> Int = fn(x, y) { 2 * x + y }

func init {
  check(add(3, 4) == 10)
  check(1 + 2 * 3 / 4 == 2)
  check(5.land(3) == 1)
  check(5.lor(3) == 7)
  check(5.lsl(3) == 40)
  check("a" < "b")
  check("aa" < "ab")
  check("aa" > "a")
}

