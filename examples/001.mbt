func init {
  printX()  
  print(a)
  nested()()
}

let a = 3

let data1 = "hello world\n"
let data2 = "\nbest xx"

func printX() {
  print(data1)
  print(data2)
}
func nested () -> () -> Unit  {
  let hi = "hi"  
  fn printY() {
    print(hi)
  }
  printY
}