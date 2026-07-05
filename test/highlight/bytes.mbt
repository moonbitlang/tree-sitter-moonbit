///|
fn main {
  let a = b"abc"
  //      ^^^^^^ string
  let b = b"\x00\xff"
  //      ^^^^^^^^^^^ string
  let c = b'a'
  //      ^^^^ character
  let d = b'\x7f'
  //      ^^^^^^^ character
}
