

type Node struct {
	data  int
	left  *Node
	right *Node
}

type BinaryTree struct {
	root *Node
}

func (bt *BinaryTree) PreOrder(node *Node, result *[]int) {
	if node != nil {
		*result = append(*result, node.data)
		bt.PreOrder(node.left, result)
		bt.PreOrder(node.right, result)
	}
}

func (bt *BinaryTree) InOrder(node *Node, result *[]int) {
	if node != nil {
		bt.InOrder(node.left, result)
		*result = append(*result, node.data)
		bt.InOrder(node.right, result)
	}
}

func (bt *BinaryTree) PostOrder(node *Node, result *[]int) {
	if node != nil {
		bt.PostOrder(node.left, result)
		bt.PostOrder(node.right, result)
		*result = append(*result, node.data)
	}
}
