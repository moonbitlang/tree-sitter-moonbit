///|
fn init {
  struct Struct {
  // <- keyword.type
    int : Int
    float : Float
  } derive(Show)
  let value = { int: 42, float: 1.0 }
  //            ^^^ variable.member
  //                      ^^^^^ variable.member
  let value = { ..value, int: 42 }
  //                     ^^^ variable.member
  let float : Float = 42.0
  let value = { ..value, float, }
  //                     ^^^^^ variable.member
  println(value)
}
