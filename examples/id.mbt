func id[T](x: T) -> T { x }

func init {
  let a = id(1)
  let b = id('c')
  let c = id(["xxx"])
}

func use_id[Y](x: Y) {
  let d = id(x)
  let e = id(Option::Some(x))
}
