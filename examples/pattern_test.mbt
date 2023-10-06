pub enum t {
    A 
    B (Int)
}

pub func hello(x : t){
    match x {
        A => print(111)
        A => print(222)
        B (_) => print(333)
    }
}


pub func hello2(x : t){
    match x {
        A | A  => print(111)
        A => print(222)
        B (_) => print(333)
    }
}

pub func hello3(x : t){
    match x {        
        A => print(444)
        B (_) => print(555)
    }
}