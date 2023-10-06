enum t1 {
  A
  B
}

enum t2 {
  A
  // both are okay because the type guides type checking

  B
}

func init {
  let x = ((fn() { A }) () : t1)
  let x = ((fn() { A }) () : t2)
  ()
}

