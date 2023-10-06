func init {
  var f = fn (x: Int) { print(x) }
  let g = fn (x: Int) { print(x+1) }
  f( { f = g; 3} )
}
