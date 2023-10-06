enum O {
  N
  S(Int)
}


pub func bind(self : O , f : (Int)->Int) -> O{
  match self {
    N => N 
    S(i) => S(f(i))
  }
}
