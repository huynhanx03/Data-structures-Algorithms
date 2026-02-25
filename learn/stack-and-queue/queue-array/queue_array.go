

type QueueArray struct {
	arr      []int
	front    int
	rear     int
	capacity int
	size     int
}

func NewQueueArray(cap int) *QueueArray {
	return &QueueArray{
		arr:      make([]int, cap),
		capacity: cap,
		front:    0,
		rear:     -1,
		size:     0,
	}
}

func (q *QueueArray) IsEmpty() bool {
	return q.size == 0
}

func (q *QueueArray) IsFull() bool {
	return q.size == q.capacity
}

func (q *QueueArray) Enqueue(value int) {
	if q.IsFull() {
		return
	}
	q.rear = (q.rear + 1) % q.capacity
	q.arr[q.rear] = value
	q.size++
}

func (q *QueueArray) Dequeue() int {
	if q.IsEmpty() {
		return -1
	}
	value := q.arr[q.front]
	q.front = (q.front + 1) % q.capacity
	q.size--
	return value
}

func (q *QueueArray) Peek() int {
	if q.IsEmpty() {
		return -1
	}
	return q.arr[q.front]
}
