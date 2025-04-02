fn main {
  println(1 + 1)
  //        ^ operator
  println(6 - 7)
  //        ^ operator
  println(2 * 3)
  //        ^ operator
  println(4 / 5)
  //        ^ operator
  println(2 % 3)
  //        ^ operator
  println(4 | 3)
  //        ^ operator
  println(4 & 3)
  //        ^ operator
  println(4 ^ 3)
  //        ^ operator
  println(2 << 3)
  //        ^^ operator
  println(2 >> 3)
  //        ^^ operator
  let mut number = 24
  //  ^^^ keyword.modifier
  number += 1
  //     ^^ operator
  number -= 1
  //     ^^ operator
  number *= 2
  //     ^^ operator
  number /= 3
  //     ^^ operator
  number %= 2
  //     ^^ operator
  println(number)
  println(1 > 2)
  //        ^ operator
  println(1 >= 2)
  //        ^^ operator
  println(1 < 2)
  //        ^ operator
  println(1 <= 2)
  //        ^^ operator
  println(1 == 2)
  //        ^^ operator
  println(1 != 2)
  //        ^^ operator
  try {
    fail!("a")
    //  ^ operator
    let result : Result[Unit, Failure] = fail?("a")
    //                                       ^ operator
    ignore(result)
  } catch {
    _ => ()
  }
}
