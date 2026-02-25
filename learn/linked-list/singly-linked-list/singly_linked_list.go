

type Node struct {
	data int
	next *Node
}

type SinglyLinkedList struct {
	head *Node
}

func (ll *SinglyLinkedList) InsertAtEnd(data int) {
	newNode := &Node{data: data}
	if ll.head == nil {
		ll.head = newNode
		return
	}
	temp := ll.head
	for temp.next != nil {
		temp = temp.next
	}
	temp.next = newNode
}

func (ll *SinglyLinkedList) DeleteNode(key int) {
	temp := ll.head
	var prev *Node

	if temp != nil && temp.data == key {
		ll.head = temp.next
		return
	}

	for temp != nil && temp.data != key {
		prev = temp
		temp = temp.next
	}

	if temp == nil {
		return
	}

	prev.next = temp.next
}

func (ll *SinglyLinkedList) Search(key int) bool {
	temp := ll.head
	for temp != nil {
		if temp.data == key {
			return true
		}
		temp = temp.next
	}
	return false
}
