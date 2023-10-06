func output_string(n: String) -> Unit {
  var i = 0
  while i < n.length() {
    print(n[i])
    i = i + 1
  }
}

enum t {
  A
  B
}

let h:t = B

let x:(t, t) = (A, A)

let y:(t, t) = (h, h)

func init {
  match (x, y) {
    ((A, A), (B, B)) => print("ok\n")
    _ => print("not ok\n")
  }
  match (x, y) {
    ((A, B), (B, B)) => print("not ok\n")
    _ => print("ok\n")
  }
  match (x, y) {
    ((A, _), (_, B)) => print("ok\n")
    (_, _) => print("not ok\n")
  }
  match (x, y) {
    ((A, _), (_, A)) => print("not ok\n")
    (_, _) => print("ok\n")
  }
  match (x, y) {
    ((A, _), (_, A)) => print("not ok\n")
    (p1, p2) =>
      match (p1, p2) {
        ((A, _), (B, B)) => print("ok\n")
        _ => print("not ok\n")
      }
  }
}

