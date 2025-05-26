///|
pub(all) enum Weekday {
  Monday
  // <- constructor
  Tuesday
  Wednesday
  Thursday
  Friday
  Sunday
} derive(Show)

///|
fn main {
  println(Monday)
  //      ^^^^^^ constructor
}
