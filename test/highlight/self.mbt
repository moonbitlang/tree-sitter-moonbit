///|
pub(all) type A Int

///|
fn to_int(self : A) -> Int {
  //      ^^^^ variable.parameter.builtin
  return self.inner()
  //     ^^^^ variable.builtin
}
