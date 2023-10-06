func println(self: Float64) {
  print_float(self)
  print("\n")
}

func init {
  let arr = [17.13, 20.23, 8.29]
  arr[0].println()
  arr[1].println()
  arr[2] = 9.29
  arr[2].println()
  arr[1] = 3.14
  arr[1].println()
  print(arr.length())
}

struct T {
  a: Float64
  mut b: Float64
  mut c: Int
}

func print_t(self: T) {
  print("\na: ")
  self.a.println()
  print("b: ")
  self.b.println()
  print("c: ")
  print(self.c)
  print("\n")
}

func f(x: T, b: Float64, c: Int) {
  x.print_t()
  x.b = b
  x.c = c
  x.print_t()
}

func init {
  let x = { a: 1.1, b: 2.2, c: 3 }
  f(x, 22.22, 33)
}

func f1(arr: Array[Float64]) {
  match arr {
    [] => print("nothing\n")
    [x] => x.println()
    [_, y] => y.println()
    [_, _, z] => z.println()
    [.., v, u, w] => { v.println(); u.println(); w.println() }
  }
}

func init {
  f1([])
  f1([1.1 ])
  f1([2.1, 2.2])
  f1([3.1, 3.2, 3.3])
  f1([4.1, 4.2, 4.3, 4.4])
  f1([5.1, 5.2, 5.3, 5.4, 5.5 ])
}


func float_down_to_0(self: Float64, f: (Float64) -> Unit) {
  if self >= 0.0 {
    f(self)
    (self - 1.0).float_down_to_0(f)
  }
}

func init {
  10.5.float_down_to_0(fn(x) {
    print_float(x)
    print("\n")
  })
}

enum h[X, Y] {
  A
  D
  E (X)
  F (Y)
}

let h:((Float64, h[Float64, Float64])) -> Float64 = fn(a) {
  match a {
    (x, D) => x * 3.0
    (x, E(y)) => x + y
    (x, F(y)) => x - y
    (y, A) => y / 1.1
  }
}

let h1:((Float64, h[Float64, Float64])) -> Float64 = fn(a) {
  (match a {
    (x, D) => x * 3.0
    (x, E(y)) => x + y
    (x, F(y)) => x - y
    (y, A) => y / 1.1
  }) * 3.0
}

func h2(self: Float64) -> Float64 {
  match self {
    1.0 => 1.5
    2.0 => 2.5
    _ => self + 1.5
  }
}

func init {
  h((1.4, h::D)).println()
  h((0.2, h::E(5.0))).println()
  h((7.3, h::F(1.1))).println()
  h((1.21, h::A)).println()
}

func init {
  h1((1.4, h::D)).println()
  h1((0.2, h::E(5.0))).println()
  h1((7.3, h::F(1.1))).println()
  h1((1.21, h::A)).println()
}

func init {
  h2(1.0).println()
  h2(2.0).println()
  h2(3.0).println()
  (if (3.0 > 4.0) { h2(4.0) } else { h2(5.0) }).println()
}
