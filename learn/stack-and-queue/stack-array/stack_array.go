

type StackArray struct {
	arr      []int
	capacity int
}

func NewStackArray(size int) *StackArray {
	return &StackArray{
		arr:      make([]int, 0, size),
		capacity: size,
	}
}

func (s *StackArray) Push(value int) {
	if len(s.arr) < s.capacity {
		s.arr = append(s.arr, value)
	}
}

func (s *StackArray) Pop() int {
	if s.IsEmpty() {
		return -1
	}
	val := s.arr[len(s.arr)-1]
	s.arr = s.arr[:len(s.arr)-1]
	return val
}

func (s *StackArray) Peek() int {
	if s.IsEmpty() {
		return -1
	}
	return s.arr[len(s.arr)-1]
}

func (s *StackArray) IsEmpty() bool {
	return len(s.arr) == 0
}

func (s *StackArray) Size() int {
	return len(s.arr)
}
