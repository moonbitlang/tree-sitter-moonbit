struct rect {
  w:Int
  h:Int
}

enum color {
  Red (Int)
  Green
  Blue
}

func area(r: rect) -> Int {
  r.w * r.h
}

func output_color(c: color) -> Unit {
  match c {
    Red(i) => {
      let color = "RED"
      print(color)
      print(i)
    }
    Green => print("Green")
    Blue => print("Blue")
  }
}

func init {
  print(area({ w:3, h:2 }))
  output_color(Red(3))
}

