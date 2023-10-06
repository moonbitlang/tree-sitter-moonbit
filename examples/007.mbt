//!build:-disable-gc
let print_int:(Int) -> Unit = fn(i) { print(i); print('\n') }

func even(n: Int) -> Bool {
  if n == 0 { true } else if n == 1 { false } else { odd(n - 1) }
}

func odd(n: Int) -> Bool {
  if n == 1 { true } else if n == 0 { false } else { even(n - 1) }
}

func init {
  var i = 0
  while i < 11 {
    print(i)
    print(' ')
    if even(i) { print_int(1) } else { print_int(0) }
    i = i + 1
  }
}

