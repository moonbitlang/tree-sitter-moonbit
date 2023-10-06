func init {
  let x = 3 // needed based on the current recovery algorithm
  {
    let x = 4
    print(x) // print 4
  }
  let z = 2
  print(x) // print 3
}

func init {
  let x = 3 // needed based on the current recovery algorithm
  {
    let x = 4
    ()
  }
  let z = 2
  print(x) // print 3
}

