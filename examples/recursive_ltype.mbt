struct Tree {
  children : Array[Tree]
}

let x : Tree = { children: [] }

func init {
  print(x.children.length())
}
