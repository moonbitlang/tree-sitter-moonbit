
let callbacks : Array [(Int) -> Int] = [fib2]

func fib2 (n : Int) -> Int {
    match n {
        0 => 0 
        1 => 1 
        _ =>  {
            a := fib2 
            // here its fvs are [fib2] which is empty 
            // if we consider it recurisve
            a(n - 1) + a(n - 2)
        }
    }
}

func init {
    print(fib2(10))
    print("\n")
    print(callbacks[0](10))
}