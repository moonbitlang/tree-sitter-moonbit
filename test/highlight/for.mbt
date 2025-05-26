///|
pub fn[T : Show] print_array(array : Array[T]) -> Unit {
  let buffer = StringBuilder::new()
  buffer.write_char('[')
  for i, value in array {
  // <- keyword.repeat
    //^ variable
    //   ^^^^^ variable
    buffer.write_object(value)
    if i < array.length() - 1 {
      buffer.write_string(", ")
    }
  }
  buffer.write_char(']')
}

///|
pub fn sum(array : Array[Int]) -> Int {
  let mut sum = 0
  for i = 0; i < array.length(); i = i + 1 {
    //^ variable
    sum += array[i]
  }
  return sum
}
