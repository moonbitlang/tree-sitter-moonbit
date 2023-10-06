enum tree[A] {
  Leaf
  Node (A, tree[A], tree[A])
}

enum single_tree[A] {
  Empty
  TNode (A, forest[A])
}

enum forest[B] {
  Nothing
  More (single_tree[B], forest[B])
}

enum t[A, B] {
  A (Int)
  B ((A) -> A)
  C (B)
  D (t[Int, Bool])
}

let x1:tree[Unit] = Leaf

let x2:tree[Char] = Node('c', Leaf, Node('d', Leaf, Leaf))

let x3:forest[Int] = More(TNode(1, Nothing), More(Empty, Nothing))

let x4:t[Unit, Unit] = A(1)

let x5:t[Int, Bool] = B(fn(x: Int) { x })

let x6:t[Unit, Char] = C('c')

let x7:t[Unit, Unit] = D(x5)

