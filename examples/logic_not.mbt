func show(x : Bool){
    if x {
        print("true\n")
    } else {
        print("false\n")
    }
}

func init{
    let a = true
    show(a)
    show(not(a))
    show(not(not(a)))
    show(not(not(not(a))))
}
