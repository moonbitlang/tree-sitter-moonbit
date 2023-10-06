/// Enum representing h with parameters M and N.
enum h[M, N] {
  A
  D
  E (M)
  F (N)
}

/// `foo(x: Int)`
///
/// A simple function that takes an `Int` and returns a `String` representing
/// the answer to life, the universe, and everything.
///
/// # Examples
/// ```moonbit
/// let answer = foo(42)
/// print(answer) // prints "42"
/// ```
func foo(x : Int) -> String {
  "42"
}

/// `inc(x: Int)`
///
/// A simple function that takes an `Int` and return its successor.
let inc : (Int) -> Int = fn(x) { x + 1 }

// Initializes and demonstrates the functions.
func init {
  // The inner function f.
  // @param {h} x - The input parameter of type h.
  let f = fn(x) {
    match x {
      // Case A in enum h.
      h::A => print('a')
      // Case E in enum h.
      // @param {Int} x - The input parameter of type Int.
      E((x:Int)) => print(x)
      // Case F in enum h.
      // @param {N} c - The input parameter of type N.
      F(c) => print('f')
    }
  }
  f(E(1)) // Example 1: Call f with E(1).
  f(A)    // Example 2: Call f with A.
  print(foo(1))

  print(inc(42)) // Example 3: Call inc with 42.
  print(dec(42))
}


/// `dec(x: Int)`
///
/// A simple function that takes an `Int` and return its predecessor.
let dec : (Int) -> Int = fn(x) { x - 1 }
