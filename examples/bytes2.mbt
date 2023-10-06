func init{
  let bytes : Bytes = Bytes::make(5, 56)
  var i = 0
  bytes[1] = 57;
  bytes[2] = 58;

  let len = bytes.length()
  print("length of bytes: \(len)\n")


  while i < 5 {
    let b = bytes[i]
    print("byte \(i): \(b)\n");
    i = i + 1
  }
  
  let a = bytes[5] //out of bound
  print(a)
  print("reading from bytes[5] should be failed\n")
  let b = bytes[-1] //out of bound
  print(b)
  print("reading from bytes[-1] should be failed\n")
}
