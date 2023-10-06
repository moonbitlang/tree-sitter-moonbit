struct reference {
  mut contents:Int
}

func init {
  let x = { contents:10, }
  fn f_1() {
    if x.contents == 0 {
      ()
    } else {
      print(x.contents)
      print('\n')
      x.contents = x.contents - 1
      f_2()
    }
  }

  fn f_2() {
    f_3()
  }

  fn f_3() {
    f_4()
  }

  fn f_4() {
    f_5()
  }

  fn f_5() {
    f_6()
  }

  fn f_6() {
    f_7()
  }

  fn f_7() {
    f_8()
  }

  fn f_8() {
    f_9()
  }

  fn f_9() {
    f_10()
  }

  fn f_10() {
    f_11()
  }

  fn f_11() {
    f_12()
  }

  fn f_12() {
    f_13()
  }

  fn f_13() {
    f_14()
  }

  fn f_14() {
    f_15()
  }

  fn f_15() {
    f_16()
  }

  fn f_16() {
    f_17()
  }

  fn f_17() {
    f_18()
  }

  fn f_18() {
    f_19()
  }

  fn f_19() {
    f_20()
  }

  fn f_20() {
    ()
  }

  f_1()
}

