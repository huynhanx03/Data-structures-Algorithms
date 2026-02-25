

type AVLNode struct {
	data   int
	height int
	left   *AVLNode
	right  *AVLNode
}

type AVLTree struct {
	root *AVLNode
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func (t *AVLTree) height(N *AVLNode) int {
	if N == nil {
		return 0
	}
	return N.height
}

func (t *AVLTree) rightRotate(y *AVLNode) *AVLNode {
	x := y.left
	T2 := x.right
	x.right = y
	y.left = T2
	y.height = max(t.height(y.left), t.height(y.right)) + 1
	x.height = max(t.height(x.left), t.height(x.right)) + 1
	return x
}

func (t *AVLTree) leftRotate(x *AVLNode) *AVLNode {
	y := x.right
	T2 := y.left
	y.left = x
	x.right = T2
	x.height = max(t.height(x.left), t.height(x.right)) + 1
	y.height = max(t.height(y.left), t.height(y.right)) + 1
	return y
}

func (t *AVLTree) getBalance(N *AVLNode) int {
	if N == nil {
		return 0
	}
	return t.height(N.left) - t.height(N.right)
}

func (t *AVLTree) Insert(data int) {
	t.root = t.insertNode(t.root, data)
}

func (t *AVLTree) insertNode(node *AVLNode, data int) *AVLNode {
	if node == nil {
		return &AVLNode{data: data, height: 1}
	}
	if data < node.data {
		node.left = t.insertNode(node.left, data)
	} else if data > node.data {
		node.right = t.insertNode(node.right, data)
	} else {
		return node
	}
	node.height = 1 + max(t.height(node.left), t.height(node.right))
	balance := t.getBalance(node)
	if balance > 1 && data < node.left.data {
		return t.rightRotate(node)
	}
	if balance < -1 && data > node.right.data {
		return t.leftRotate(node)
	}
	if balance > 1 && data > node.left.data {
		node.left = t.leftRotate(node.left)
		return t.rightRotate(node)
	}
	if balance < -1 && data < node.right.data {
		node.right = t.rightRotate(node.right)
		return t.leftRotate(node)
	}
	return node
}
