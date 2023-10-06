struct r1 {
  x:Int
  y:Bool
}

enum t {
  A
  B (Int, Int)
  C
}

let p1:r1 = { x:3, y:true }

func print_tag_and_len[T] (o: T) -> Unit {
  print(unsafe_obj_block_tag(o))
  print(", ")
  print(unsafe_obj_block_length(o))
  print('\n')
}

func fib(n: Int) -> Int {
  match n {
    0 | 1 => 1
    _ => fib(n - 1) + fib(n - 2)
  }
}

func init {
  print("String:\n")
  print_tag_and_len("")
  print_tag_and_len("a")
  print_tag_and_len("aa")
  print_tag_and_len("aaa")
  print_tag_and_len("aaaa")
  print_tag_and_len("aaaaa")
  print("Array:\n")
  print_tag_and_len([])
  print_tag_and_len([1])
  print_tag_and_len([1, 2])
  print("tuple:\n")
  print_tag_and_len((1, 2))
  print_tag_and_len((1, 2, 3))
  print("record:\n")
  print_tag_and_len(p1)
  print("adt:\n")
  print_tag_and_len(t::A)
  print_tag_and_len(t::B(1, 2))
  print_tag_and_len(t::C)
  print("closure:\n")
  let x = 1
  fn f() {
    x
  }

  print_tag_and_len(f)
  let y = 2
  fn g() {
    x + y
  }

  print_tag_and_len(g)
}

