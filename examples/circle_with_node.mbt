//!build:-disable-gc
func init {
  let z = 0
  fn id(x) {
    x
  }

  fn even(x) {
    if x == z { true } else { odd(x - 1) }
  }

  fn odd(x) {
    if x == 0 { false } else { even(x - 1) }
  }

  let _ = id(even) // make sure even and odd won't be optimized
  let _ = id(odd)
  print(if even(6) { 1 } else { 0 })
}

