

type StackNode struct {
	data int
	next *StackNode
}

type StackLinkedList struct {
	top *StackNode
}

func (s *StackLinkedList) Push(value int) {
	newNode := &StackNode{data: value, next: s.top}
	s.top = newNode
}

func (s *StackLinkedList) Pop() int {
	if s.IsEmpty() {
		return -1
	}
	value := s.top.data
	s.top = s.top.next
	return value
}

func (s *StackLinkedList) Peek() int {
	if s.IsEmpty() {
		return -1
	}
	return s.top.data
}

func (s *StackLinkedList) IsEmpty() bool {
	return s.top == nil
}
