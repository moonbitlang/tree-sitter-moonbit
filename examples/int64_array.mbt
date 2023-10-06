func init {
  let xs = Array::make(10, 100L)
  xs[0] = 123L
  println(xs[0])
  println(xs[1])
}

func init {
  let xs = [123L, 456L, 789L]
  xs[2] = 921L
  println(xs[1])
  println(xs[2])
}
