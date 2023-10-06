func printTest[X:Show](x : X) {
  print(x.to_string())
}

func init {
  printTest(222)
}
