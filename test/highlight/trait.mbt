///|
trait T {
// <- keyword.type
  //  ^ type.definition
  a(Self, self : Self, a~ : Int) -> Unit
  // <- function
  //^^^^ type.builtin
  //      ^^^^ variable.parameter.builtin
  //                   ^ variable.parameter
}
