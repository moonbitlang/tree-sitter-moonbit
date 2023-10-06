func init {
  // oop style method call
  print([1, 2, 3].to_string())
}


func to_string[T : Show](self : Array[T]) -> String {
  var str = ""
  var i = 0
  while i < self.length(){
    str = str + self[i].to_string()
    i = i + 1
  }
  str
}
