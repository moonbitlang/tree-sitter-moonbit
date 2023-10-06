enum t {
  A
  B
}

func init {
  let c : t = B
  let d : t = A
  match d {
    A => print("ok")
    B => print("notok")
  }
  match c {
    A => print("notok")
    B => print("ok")
  }
}

