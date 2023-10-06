func init {
  let result = Result::Ok("ok!")
  match result {
    Ok(i) => println(i)
    Err(e) => println(e + 1)
  }
  println("test builtin package in dev")
}

func init{
  let a = true.to_string()
  println(a)
  println(false)
}