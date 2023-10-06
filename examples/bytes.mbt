func init{
  let bytes : Bytes = Bytes::make(3, 56)
  var i = 0
  bytes[1] = 57;
  bytes[2] = 58;

  let len = bytes.length()
  print("length of bytes: \(len)\n")


  while i < 3 {
    let b = bytes[i]
    print("byte \(i): \(b)\n");
    i = i + 1
  }

  bytes[3] = 57 //out of bound
  print("access to bytes[3] should be failed")
  bytes[-1] = 57 //out of bound
  print("access to bytes[-1] should be failed")
}
