
// an immutable iterator over integer
interface Iter {
  next(Self) -> Option[(Int, Self)]
}

func for[I: Iter](i: I, f: (Int) -> Unit) {
  match i.next() {
    None => ()
    Some(elt, next) => {
      f(elt)
      for(next, f)
    }
  }
}


struct Range {
  beg: Int
  end: Int
}

func range(beg: Int, end: Int) -> Range {
  { beg, end }
}

func next(self: Range) -> Option[(Int, Range)] {
  if self.beg >= self.end {
    None
  } else {
    Some(self.beg, { ..self, beg: self.beg + 1 })
  }
}


struct ArrayIter {
  arr: Array[Int]
  idx: Int
}

func next(self: ArrayIter) -> Option[(Int, ArrayIter)] {
  if self.idx >= self.arr.length() {
    None
  } else {
    Some(self.arr[self.idx], { ..self, idx: self.idx + 1 })
  }
}


func Array::iter(arr: Array[Int]) -> ArrayIter {
  { arr, idx: 0 }
}


func init {
  for(range(1, 10), fn (i) { print("\(i)\n") })
  print("====\n")
  for(Array::iter([1, 2, 3, 4, 5]), fn (i) { print("\(i)\n") })
}
