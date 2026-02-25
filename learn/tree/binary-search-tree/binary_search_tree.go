

type BSTNode struct {
	data  int
	left  *BSTNode
	right *BSTNode
}

type BinarySearchTree struct {
	root *BSTNode
}

func (bst *BinarySearchTree) Insert(data int) {
	if bst.root == nil {
		bst.root = &BSTNode{data: data}
	} else {
		bst.insertNode(bst.root, data)
	}
}

func (bst *BinarySearchTree) insertNode(node *BSTNode, data int) {
	if data < node.data {
		if node.left == nil {
			node.left = &BSTNode{data: data}
		} else {
			bst.insertNode(node.left, data)
		}
	} else {
		if node.right == nil {
			node.right = &BSTNode{data: data}
		} else {
			bst.insertNode(node.right, data)
		}
	}
}

func (bst *BinarySearchTree) Search(data int) bool {
	return bst.searchNode(bst.root, data)
}

func (bst *BinarySearchTree) searchNode(node *BSTNode, data int) bool {
	if node == nil {
		return false
	}
	if data < node.data {
		return bst.searchNode(node.left, data)
	} else if data > node.data {
		return bst.searchNode(node.right, data)
	}
	return true
}
