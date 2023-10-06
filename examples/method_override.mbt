pub struct Foo[T] {
  foo:T
}

pub func to_string[T: Show](self: Foo[T]) -> String {
  self.foo.to_string()
}

pub struct Bar[T, S] {
  bar:T
  baz:S
}

pub func to_string[T: Show, S: Show](self: Bar[T, S]) -> String {
  "\nhe" + self.bar.to_string() + "\nworld" + self.baz.to_string()
}

pub enum Opt[T] {
  Nothing
  Just(T)
}

pub func to_string[T: Show](self: Opt[T]) -> String {
  match self {
    Nothing => "nothing"
    Just(x) => x.to_string()
  }
}

pub func to_string(self: String) -> String {
  "~" + self + "~"
}

pub func to_string[T:Show](self: Option[T]) -> String {
  match self {
    None => "none"
    Some(x) => "#" + x.to_string() + "#"
  }
}

func init {
  let x: Foo[_] = { foo: 1 }
  let ox: Opt[_] = Just(x)
  print(ox.to_string())
  let y: Bar[_] = { bar: "llo", baz: Option::Some('!')}
  let oy: Opt[_] = Just(y)
  print(oy.to_string())
}
