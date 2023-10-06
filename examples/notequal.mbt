
struct T {
  x: Int
}

func op_equal(self: T, other: T) -> Bool {
  not(self.x != other.x)
}

func init {
  let t = { x: 1 }
  if t != t {
    print("Boom!")
  } else {
    print("Ok!")
  }
}
