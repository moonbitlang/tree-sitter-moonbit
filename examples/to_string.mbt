func init {
  let printable = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~"
  var i = 0
  while i < printable.length() {
    print(printable[i].to_string())
    i = i + 1
  }
  print('\n'.to_string())
}

func init {
  let xs = [0, 1, 12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789]
  var i = 0
  while i < xs.length() {
    print(xs[i].to_string())
    print("\n")
    let y = xs[i].op_neg()
    print(y.to_string())
    print("\n")
    i = i + 1
  }
}

