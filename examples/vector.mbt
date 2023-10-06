
struct Vector[X] {
  mut data: Array[X]
  mut len: Int
}

func length[X](self: Vector[X]) -> Int {
  self.len
}

func capacity[X](self: Vector[X]) -> Int {
  self.data.length()
}


func Vector::new_with_default[X](cap: Int, default: X) -> Vector[X] {
  { data: Array::make(cap, default), len: 0 }
}

func Vector::new[X: Default](cap: Int) -> Vector[X] {
  Vector::new_with_default(cap, X::default())
}


func op_get[X](self: Vector[X], i: Int) -> Option[X] {
  if i < self.len { Some(self.data[i]) } else { None }
}


func push_back_with_default[X](self: Vector[X], elem: X, default: X) {
  if self.len < self.data.length() {
    self.data[self.len] = elem
    self.len = self.len + 1
  } else {
    let old_cap = self.data.length()
    let new_cap = if old_cap == 0 { 10 } else { old_cap * 2 }
    let new_data = Array::make(self.data.length() * 2, default)
    var i = 0
    while i < self.len {
      new_data[i] = self.data[i]
      i = i + 1
    }
    new_data[self.len] = elem
    self.data = new_data
    self.len = self.len + 1
  }
}

func push_back[X: Default](self: Vector[X], elem: X) {
  self.push_back_with_default(elem, X::default())
}


struct T { x: Int }
struct U { y: Int }

func T::default() -> T {
  { x: 0 }
}

func init {
  let v1 = Vector::new(2)
  v1.push_back({ x: 0 })
  v1.push_back({ x: 1 })
  v1.push_back({ x: 2 })
  v1.push_back({ x: 3 })
  var i = 0
  while (i < v1.length()) {
    match v1[i] {
      Some(t) => print(t.x)
      None => ()
    }
    i = i + 1
  }
  print("\n")

  let v2 = Vector::new_with_default(2, { y: 0 })
  v2.push_back_with_default({ y: 0 }, { y: 0 })
  v2.push_back_with_default({ y: 1 }, { y: 0 })
  v2.push_back_with_default({ y: 2 }, { y: 0 })
  v2.push_back_with_default({ y: 3 }, { y: 0 })
  var i = 0
  while (i < v2.length()) {
    match v2[i] {
      Some(u) => print(u.y)
      None => ()
    }
    i = i + 1
  }
  print("\n")

  let v3 = Vector::new(2)
  v3.push_back(0.1)
  v3.push_back(1.1)
  v3.push_back(2.1)
  v3.push_back(3.1)
  var i = 0
  while (i < v3.length()) {
    match v3[i] {
      Some(x) => print_float(x)
      None => ()
    }
    i = i + 1
  }
  print("\n")
}
