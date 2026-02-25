

type QueueNode struct {
	data int
	next *QueueNode
}

type QueueLinkedList struct {
	front *QueueNode
	rear  *QueueNode
}

func (q *QueueLinkedList) IsEmpty() bool {
	return q.front == nil
}

func (q *QueueLinkedList) Enqueue(value int) {
	newNode := &QueueNode{data: value}
	if q.rear == nil {
		q.front = newNode
		q.rear = newNode
		return
	}
	q.rear.next = newNode
	q.rear = newNode
}

func (q *QueueLinkedList) Dequeue() int {
	if q.IsEmpty() {
		return -1
	}
	value := q.front.data
	q.front = q.front.next
	if q.front == nil {
		q.rear = nil
	}
	return value
}

func (q *QueueLinkedList) Peek() int {
	if q.IsEmpty() {
		return -1
	}
	return q.front.data
}
