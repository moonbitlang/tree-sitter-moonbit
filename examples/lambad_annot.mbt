enum t {
  A
  B
}

func init {
  let a = fn()-> t { if true { A } else { B } }
  match a() {
    A => print("A")
    B => print("B")
  }
}

