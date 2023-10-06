func has[T] (self: Array[T], f: (T) -> Bool) -> Bool {
  var i = 0
  while i < self.length() {
    if f(self.get(i)) { return true }
    i = i + 1
  }
  return false
}

func init {
  if [1, 2, 3].has(fn(x) { x > 2 }) { print("ok") }
  if [1, 2, 3].has(fn(x) { x > 4 }) { print("not ok") } else { print("ok") }
}

