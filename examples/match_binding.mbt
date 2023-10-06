
enum T {
  A(Int)
  B(Option[Int])
  C(Int, Int)
}

func f1(x: T) {
  match x {
    B(Some(x)) | A(x) => print(x)
    B(None as y) =>
      match y {
        Some(_) => print("bad")
        None => print("good")
      }
    C(x, 1 as y) | C(2 as y, x) => print(x - y)
    C(x, y) => print(x * y)
  }
}

func init {
  f1(T::A(1))
  f1(T::B(None))
  f1(T::B(Some(2)))
  f1(T::C(2, 1))
  f1(T::C(3, 1))
  f1(T::C(2, 3))
  f1(T::C(1, 2))
}
