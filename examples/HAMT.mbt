
// count the number of "1"s in a 32-bit integer
func ctpop(n: Int) -> Int {
  // extract the lower bit of every 2-bit group
  let low_of_2bits = 1431655765 // 0x55555555
  // count the number of "1"s in every 2-bit group
  // store the result in the same 2-bit group
  let c2 = n.land(low_of_2bits) + n.lsr(1).land(low_of_2bits)
  // count the number of "1"s in every 4-bit group (i.e. two 2-bit groups),
  // store the result in the same 4-bit group
  let low_of_4bits = 858993459 // 0x33333333
  let c4 = c2.land(low_of_4bits) + c2.lsr(2).land(low_of_4bits)
  // similarly for every 8-bit group
  let low_of_8bits = 252645135 // 0x0f0f0f0f
  let c8 = c4.land(low_of_8bits) + c4.lsr(4).land(low_of_8bits)
  // 16-bit group.
  // there will be only two groups left, without rist of overlapping,
  // so there's no need to clean the unused higher bits
  let c16 = c8 + c8.lsr(8)
  // the final 32-bit group
  // [ctpop(x) <= 32], so only the last 6 bits are meaningful
  let lower_6bits = 63 // 0x3f
  (c16 + c16.lsr(16)).land(lower_6bits)
}


// a simple bit set to store a set of integers less than 32
struct Bitset {
  rep: Int
}

let empty_bitset: Bitset = { rep: 0 }

func has(self: Bitset, idx: Int) -> Bool {
  self.rep.land(1.lsl(idx)) != 0
}

func index_of(self: Bitset, idx: Int) -> Int {
  let items_below_idx = self.rep.land(1.lsl(idx) - 1)
  ctpop(items_below_idx)
}

func add(self: Bitset, idx: Int) -> Bitset {
  { rep: self.rep.lor(1.lsl(idx)) }
}

func remove(self: Bitset, idx: Int) -> Bitset {
  { rep: self.rep.lxor(1.lsl(idx)) }
}


// A sparse array with at most 32 elements, where elements are not required to have contiguous index.
// Empty elements don't waste any space, without losing constant-time access
struct Sparse_Array[X] {
  // record which elements are present
  elem_info: Bitset
  data: Array[X]
}

func make_sparse_array[X](idx: Int, value: X) -> Sparse_Array[X] {
  { elem_info: empty_bitset.add(idx), data: [ value ] }
}

func has[X](self: Sparse_Array[X], idx: Int) -> Bool {
  self.elem_info.has(idx)
}

func op_get[X](self: Sparse_Array[X], idx: Int) -> Option[X] {
  if self.elem_info.has(idx) {
    Some (self.data[self.elem_info.index_of(idx)])
  } else {
    None
  }
}

// add a new element into the sparse array.
// [idx] must be absent from [self]
func add[X](self: Sparse_Array[X], idx: Int, value: X) -> Sparse_Array[X] {
  let new_len = self.data.length() + 1
  let pos_of_new_item = self.elem_info.index_of(idx)
  let new_data = Array::make(new_len, value)
  var i = 0
  while (i < pos_of_new_item) {
    new_data[i] = self.data[i]
    i = i + 1
  }
  new_data[i] = value
  i = i + 1
  while (i < new_len) {
    new_data[i] = self.data[i - 1]
    i = i + 1
  }
  { elem_info: self.elem_info.add(idx), data: new_data }
}

// replace an existing element in the sparse array.
func replace[X](self: Sparse_Array[X], idx: Int, value: X) -> Sparse_Array[X] {
  let len = self.data.length()
  let pos_of_new_item = self.elem_info.index_of(idx)
  let new_data = Array::make(len, value)
  var i = 0
  while (i < len) {
    new_data[i] = if i == pos_of_new_item { value } else { self.data[i] }
    i = i + 1
  }
  { elem_info: self.elem_info, data: new_data }
}


// Hash-Array-Mapped-Trie (HAMT) is a persistent hash-table data structure.
// It is a trie over the hash of keys (i.e. strings of binary digits)
// 
// Every level in a HAMT can have up to 32 branches (5 digits),
// so HAMT has a tree height of at most 7,
// and is more efficient compared to most other tree data structures.
// 
// HAMT uses the bitmap-based sparse array above to avoid space waste
enum HAMT[K, V] {
  Empty
  Leaf(K, V) // optimize for the case of no collision
  Collision(Bucket[K, V]) // use a list of buckets to resolve collision
  Branch(Sparse_Array[HAMT[K, V]])
}

enum Bucket[K, V] {
  Just_One(K, V) // must be non-empty
  More(K, V, Bucket[K, V])
}

// The number of bits consumed at every [Branch] node
let segment_length: Int = 5

func make[K, V]() -> HAMT[K, V] {
  Empty
}

func find_with_hash[K: Eq, V](self: HAMT[K, V], key: K, hash: Int) -> Option[V] {
  match self {
    Empty => None
    Leaf(key1, value) => {
      if key == key1 { Some(value) } else { None }
    }
    Collision(bucket) => bucket.find(key)
    Branch(children) => {
      // get the first segment (lower 5 bits) of the hash value
      let idx = hash.land(1.lsl(segment_length) - 1)
      match children[idx] {
        Some(child) =>
          // when searching recursively, drop the segment just used
          child.find_with_hash(key, hash.lsr(segment_length))
        None => None
      }
    }
  }
}

func find[K: Eq + Hash, V](self: HAMT[K, V], key: K) -> Option[V] {
  self.find_with_hash(key, key.hash())
}

func add_with_hash[K: Eq, V](
  self: HAMT[K, V],
  key: K,
  depth: Int,
  hash: Int,
  value: V) -> HAMT[K, V] {
  // make sure leaf nodes always appear at the bottom of the tree
  fn make_leaf(depth: Int, key: K, hash: Int, value: V) {
    if (depth >= 32) {
      HAMT::Leaf(key, value)
    } else {
      let idx = hash.land(1.lsl(segment_length) - 1)
      let child = make_leaf(depth + segment_length, key, hash.lsr(segment_length), value)
      HAMT::Branch(make_sparse_array(idx, child))
    }
  }
  match self {
    Empty => make_leaf(depth, key, hash, value)
    Leaf(key1, value1) => {
      if key == key1 {
        Leaf(key, value)
      } else {
        Collision(More(key, value, Just_One(key1, value1)))
      }
    }
    Collision(bucket) => {
      Collision(bucket.add(key, value))
    }
    Branch(children) => {
      let idx = hash.land(1.lsl(segment_length) - 1)
      match children[idx] {
        Some(child) => {
          let child = child.add_with_hash(key, depth + segment_length, hash.lsr(segment_length), value)
          Branch(children.replace(idx, child))
        }
        None => {
          let child = make_leaf(depth + segment_length, key, hash.lsr(segment_length), value)
          Branch(children.add(idx, child))
        }
      }
    }
  }
}

func add[K: Eq + Hash, V](self: HAMT[K, V], key: K, value: V) -> HAMT[K, V] {
  self.add_with_hash(key, 0, key.hash(), value)
}


func size[K, V](self: HAMT[K, V]) -> Int {
  match self {
    Empty => 0
    Leaf(_) => 1
    Collision(bucket) => bucket.size()
    Branch(children) => {
      var total_size = 0
      var i = 0
      while (i < children.data.length()) {
        total_size = total_size + children.data[i].size()
        i = i + 1
      }
      total_size
    }
  }
}

func count_collision[K, V](self: HAMT[K, V]) -> Int {
  match self {
    Empty | Leaf(_) => 0
    Collision(bucket) => bucket.size()
    Branch(children) => {
      var total_count = 0
      var i = 0
      while (i < children.data.length()) {
        total_count = total_count + children.data[i].count_collision()
        i = i + 1
      }
      total_count
    }
  }
}

func print_hamt[K: Show, V: Show](self: HAMT[K, V], indent: Int) {
  match self {
    Empty => print("Empty\n")
    Leaf(k, v) => print("\(k) => \(v)\n")
    Collision(bucket) => print_bucket(bucket)
    Branch(children) =>
      if (children.data.length() == 0) {
        print("Empty\n")
      } else {
        print("Branch\n")
        var i = 0
        var j = 0
        while (i < 32) {
          match children[i] {
            Some(child) => {
              var n = 0
              while (n < indent) {
                print(' ')
                n = n + 1
              }
              print("#\(i)\n")
              var n = 0
              while (n < indent) {
                print(' ')
                n = n + 1
              }
              print("- ")
              children.data[j].print_hamt(indent + 2)
              j = j + 1
            }
            None => ()
        }
        i = i + 1
      }
    }
  }
}


// bucket operations
func find[K: Eq, V](self: Bucket[K, V], key: K) -> Option[V] {
  match self {
    Just_One(key1, value) => {
      if key == key1 { Some(value) } else { None }
    }
    More(key1, value, rest) => {
      if key == key1 { Some(value) } else { rest.find(key) }
    }
  }
}

func add[K: Eq, V](self: Bucket[K, V], key: K, value: V) -> Bucket[K, V] {
  match self {
    Just_One(key1, value1) => {
      if key == key1 {
        Just_One(key, value)
      } else {
        More(key, value, self)
      }
    }
    More(key1, value1, rest) => {
      if key == key1 {
        More(key, value, rest)
      } else {
        More(key1, value1, rest.add(key, value))
      }
    }
  }
}

func size[K, V](self: Bucket[K, V]) -> Int {
  match self {
    Just_One(_) => 1
    More(_, _, rest) => rest.size() + 1
  }
}

func print_bucket[K: Show, V: Show](self: Bucket[K, V]) {
  match self {
    Just_One(k, v) => print("\(k) => \(v)\n")
    More(k, v, rest) => {
      print("\(k) => \(v); ")
      print_bucket(rest)
    }
  }
}


// simulate a character string with array of int
struct My_Key {
  data: Array[Int]
}

// assume only the lower 28-bits of the integer is meaningful
func hash(self: My_Key) -> Int {
  var h = 1571940757
  var i = 0
  while (i < self.data.length()) {
    let higher_4 = h.land(251658240) // 0xf000000
    h = h.lsl(4).lor(h.land(higher_4).lsr(24)).lxor(self.data[i])
    i = i + 1
  }
  h
}

func op_equal(self: My_Key, other: My_Key) -> Bool {
  let len = self.data.length()
  if len != other.data.length() {
    return false
  }

  var i = 0
  while (i < len) {
    if (self.data[i] != other.data[i]) {
      return false
    }
    i = i + 1
  }
  true
}

func to_string(self: My_Key) -> String {
  var s = "";
  var i = 0
  while (i < self.data.length()) {
    if i > 0 {
      s = s + "," + self.data[i].to_string()
    } else {
      s = self.data[i].to_string()
    }
    i = i + 1
  }
  s
}

func make_key(seed: Int) -> My_Key {
  let len = seed % 3 + 2
  var i = 0
  var h = seed
  let data = Array::make(len, 0)
  while (i < len) {
    data[i] = h
    h = (28585281 * h + 1750028503).land(16777215) // take the lower 28 bits
    i = i + 1
  }
  { data: data }
}

func init {
    let n = 10
    var hamt = make()
    var i = 0
    while (i < n) {
      hamt = hamt.add(make_key(i), i)
      i = i + 1
    }

    let collision_count = hamt.count_collision()
    print("number of collision: \(collision_count)\n")
    // uncomment this to see the tree (large trees may not display properly)
    // hamt.print(0)

    var is_ok = true
    var i = 0
    while (i < n) {
      match hamt.find(make_key(i)) {
        Some(v) =>
          if v != i {
            is_ok = false
            print("\(i): wrong value\n")
          }
        None => {
          is_ok = false
          print("\(i): not found\n")
        }
      }
      i = i + 1
    }

    if (is_ok) {
      print("OK!\n")
    }
}
