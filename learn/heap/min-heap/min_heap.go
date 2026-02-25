

type MinHeap struct {
	arr []int
}

func (h *MinHeap) Insert(val int) {
	h.arr = append(h.arr, val)
	h.heapifyUp(len(h.arr) - 1)
}

func (h *MinHeap) ExtractMin() int {
	if len(h.arr) == 0 {
		return -1
	}
	min := h.arr[0]
	h.arr[0] = h.arr[len(h.arr)-1]
	h.arr = h.arr[:len(h.arr)-1]
	h.heapifyDown(0)
	return min
}

func (h *MinHeap) heapifyUp(index int) {
	for index > 0 {
		parent := (index - 1) / 2
		if h.arr[index] < h.arr[parent] {
			h.arr[index], h.arr[parent] = h.arr[parent], h.arr[index]
			index = parent
		} else {
			break
		}
	}
}

func (h *MinHeap) heapifyDown(index int) {
	for {
		left := 2*index + 1
		right := 2*index + 2
		smallest := index

		if left < len(h.arr) && h.arr[left] < h.arr[smallest] {
			smallest = left
		}
		if right < len(h.arr) && h.arr[right] < h.arr[smallest] {
			smallest = right
		}
		if smallest != index {
			h.arr[index], h.arr[smallest] = h.arr[smallest], h.arr[index]
			index = smallest
		} else {
			break
		}
	}
}
