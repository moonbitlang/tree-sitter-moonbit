///|
extenum Event {
// <- keyword.type
//      ^^^^^ type.definition
  Started
  // <- constructor
}

///|
extenum Event += {
// <- keyword.type
//      ^^^^^ type
//            ^^ operator
  Stopped
  // <- constructor
}

///|
declare extenum @base.Event += {
// <- keyword.modifier
//      ^^^^^^^ keyword.type
//              ^^^^^ module
//                   ^^^^^^ type
//                          ^^ operator
  Paused
  // <- constructor
}
