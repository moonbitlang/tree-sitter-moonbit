///|
pub(all) type Type Int derive(Show)

///|
fn Type::function(self : Type) -> Unit {
  ignore(self)
}

///|
fn main {
  let variable : Type = 0
  variable..function()
  //      ^^ punctuation.delimiter
  //        ^^^^^^^^ function.method.call
  let string = "hello"
  match string {
    [.. "hello", .. string] =>
     // <- operator
      //         ^^ operator
      println(string)
    [.. string] => println(string)
  }
  for i in 0..<3 {
    //      ^^^ operator
  }
  for j in 0..=2 {
    //      ^^^ operator
  }
}
