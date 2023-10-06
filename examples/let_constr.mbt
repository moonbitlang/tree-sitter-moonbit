enum t {
  A
  Bbb
}

func init {
  let x : t = A
  let y = t::A
  let z = t::Bbb
  ()
}

func hello() -> t {
  Bbb
}

func init {
  let x = fn() { t::Bbb }
  ()
}

