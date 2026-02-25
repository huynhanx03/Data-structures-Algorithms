

type DNode struct {
	data int
	prev *DNode
	next *DNode
}

type DoublyLinkedList struct {
	head *DNode
}

func (dll *DoublyLinkedList) InsertAtEnd(data int) {
	newNode := &DNode{data: data}
	if dll.head == nil {
		dll.head = newNode
		return
	}
	temp := dll.head
	for temp.next != nil {
		temp = temp.next
	}
	temp.next = newNode
	newNode.prev = temp
}

func (dll *DoublyLinkedList) DeleteNode(key int) {
	temp := dll.head
	for temp != nil && temp.data != key {
		temp = temp.next
	}
	if temp == nil {
		return
	}
	if temp.prev != nil {
		temp.prev.next = temp.next
	} else {
		dll.head = temp.next
	}
	if temp.next != nil {
		temp.next.prev = temp.prev
	}
}

func (dll *DoublyLinkedList) Search(key int) bool {
	temp := dll.head
	for temp != nil {
		if temp.data == key {
			return true
		}
		temp = temp.next
	}
	return false
}
