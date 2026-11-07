///|
pub(all) enumview V {
//       ^^^^^^^^ keyword.type
//                ^ type.definition
  SNil
  // <- constructor
  SCons(String)
  // <- constructor
} for List[Int] with view(x : List[Int]) {
  //                 ^^^^ function
  //                      ^ variable.parameter
  match x {
    Nil => SNil
    // <- constructor
    Cons(y, ys) => SCons(y.to_string(), ys)
    //   ^ variable
  }
}
