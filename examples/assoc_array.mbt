pub struct map[K, V] {
  entries: Array[(K, V)]
}


pub func find[K : Eq, V](self: map[K, V], key: K) -> Option[V] {
  var i = 0
  while i < self.entries.length() {
    let (k, v) = self.entries[i]
    if (key == k) {
        return Some(v)
    } else {
        i = i + 1
    }
  }
  return None
}

pub enum T {
  A
  B
  C
}

pub struct ST {
  x: T
}

pub func op_equal(self: T, other: T) -> Bool {
  match (self, other) {
    (A, A) | (B, B) | (C, C) => true
    _ => false
  }
}

pub func op_equal(self : ST, other : ST) -> Bool {
  self.x == other.x
}

func iter[X](self: Option[X], f: (X) -> Unit) {
  match self {
    Some(x) => f(x)
    None => ()
  }
}

func init {
    let map1: map[T, _] = { entries: [(A, "ok\n"), (B, "not ok\n"), (C, "not ok\n")] }
    let map2 = { entries: [("a", 0), ("b", 1), ("c", 2)] }
    let map3: map[ST, _] = { entries: [({x: A}, 1.28), ({x: B}, 2.56), ({x: C}, 3.14)] }
    map1.find(A).iter(fn (v) { print(v) })
    map2.find("b").iter(fn (v) { print(v) })
    map3.find({x: C}).iter(fn (v) { print_float(v) })
}
