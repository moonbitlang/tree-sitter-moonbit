let x = 1 

func add (y:Int) -> Int {
    y + x
}


func call_add(z : Int) -> Int {
    add(add(z))
}

func init {
    print(call_add(2))
}