enum E {
  E(e~ : Int, f~ : Int)
}

///|
fn main {
  let a = 1
  //  ^ variable
  let b = 2
  match (a, b) {
    //   ^ variable
    //      ^ variable
    (c, d) => println(c + d)
  // ^ @variable
    //  ^ @variable
  }
  let e = E(e=1, f=2)
  //  ^ variable
  //        ^ variable.member
  //             ^ variable.member
  match e {
    E(e~, f=g) => {
      // <- variable
      //  ^ variable.member
      //    ^ variable
      println(e + g)
    }
  }
}
