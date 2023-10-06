
struct T {
  x: Bool
  y: Option[Bool]
}


func r1(t: T) -> Int {
  match t {
    { x: true , y: None } => 1
    { x: false, y: Some(_) } => 2
    { x: _,     y: Some(false) } => 3
    { x: true , y: Some(true) } => 4
  }
}


func r2(t: T) -> Int {
  match t {
    { x: true, .. } => 1
    { y: Some(x), .. } => if x { 2 } else { 3 }
    { x: false, y: None } => 4
  }
}

func a1(arr: Array[Bool]) -> Int {
  match arr {
    [] => 1
    [true] => 2
    [_, false] => 3
    [false] => 4
    [true, _] => 5
    _ => 6
  }
}


func a2(arr: Array[Int]) -> Int {
   match arr {
     [] => 0
     [x] => -x
     [x, y] => x + y
     [.., x, y] => y - x
   }
}

func a3(arr: Array[Int]) {
   match arr {
     [] => print(0)
     [_] => print(1)
     [_, _] => print(2)
     [_, _, _] => print(3)
     [.., x, y, z, w] => { print(x); print(y); print(z); print(w) }
   }
}


func empty(x: Int) -> Int {
  match x {
  }
}

func init {
  print(r1({ x: true , y: None }))
  print("X") // { x: false, y: None } is unmatched
  print(r1({ x: true , y: Some(true ) }))
  print(r1({ x: true , y: Some(false) }))
  print(r1({ x: false, y: Some(true ) }))
  print(r1({ x: false, y: Some(false) }))
  print("\n===\n")

  print(r2({ x: true , y: None }))
  print(r2({ x: true , y: Some(true ) }))
  print(r2({ x: true , y: Some(false) }))
  print(r2({ x: false, y: None }))
  print(r2({ x: false, y: Some(true ) }))
  print(r2({ x: false, y: Some(false) }))
  print("\n===\n")

  print(a1([]))
  print(a1([true ]))
  print(a1([false]))
  print(a1([true , true ]))
  print(a1([true , false]))
  print(a1([false, true ]))
  print(a1([false, false]))
  print(a1([true, true, true]))
  print("\n===\n")

  print(a2([]))
  print(a2([9]))
  print(a2([2, 3]))
  print(a2([3, 4, 5]))
  print("\n===\n")

  // print(empty(0))
  a3([20, 23, 9, 1])
}
