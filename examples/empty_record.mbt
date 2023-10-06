struct empty_record {

}

func hello(x: empty_record) {
  let h : empty_record = {  }
  match h {
    {} => print("ok\n")
  }
  let y : Option[_] = None
  match (x, y) {
    ({}, Some(x)) => print("not ok")
    (_, None) => print("ok\n")
  }
}

func init {
  hello({  })
}

