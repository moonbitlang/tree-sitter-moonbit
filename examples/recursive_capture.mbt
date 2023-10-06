func fib (n : Int) -> Int {
    match n {
        0 => 0 
        1 => 1 
        _ =>  {
            a := fib 
            a(n - 1) + a(n - 2)
        }
    }
}

func init {
    print(fib(10))
}