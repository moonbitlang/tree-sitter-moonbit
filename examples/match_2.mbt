enum T {
  A
  B (Int, Int)
  C
}

func init {
  match (false, T::B(2, 4)) {
    (_, A) => print('0')
    (true, B(i, j)) => ()
    (_, B(i, j)) => { print(i); print(j) }
    (_, C) => print('2')
  }
}

enum H[M, N] {
  A1
  D
  E (M)
  F (N)
}

func init {
  let x : H[Int, Int] = H::E(1)
  let i = match x {
    A1 => 0
    E(x) => x
    _ => 2
  }
  print(i)
}

func init {
  let x = (1, 2)
  match x {
    (x, y) => print(x + y)
  }
}

