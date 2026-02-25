

type MaxHeap struct {
	arr []int
}

func (h *MaxHeap) Insert(val int) {
	h.arr = append(h.arr, val)
	h.heapifyUp(len(h.arr) - 1)
}

func (h *MaxHeap) ExtractMax() int {
	if len(h.arr) == 0 {
		return -1
	}
	max := h.arr[0]
	h.arr[0] = h.arr[len(h.arr)-1]
	h.arr = h.arr[:len(h.arr)-1]
	h.heapifyDown(0)
	return max
}

func (h *MaxHeap) heapifyUp(index int) {
	for index > 0 {
		parent := (index - 1) / 2
		if h.arr[index] > h.arr[parent] {
			h.arr[index], h.arr[parent] = h.arr[parent], h.arr[index]
			index = parent
		} else {
			break
		}
	}
}

func (h *MaxHeap) heapifyDown(index int) {
	for {
		left := 2*index + 1
		right := 2*index + 2
		largest := index

		if left < len(h.arr) && h.arr[left] > h.arr[largest] {
			largest = left
		}
		if right < len(h.arr) && h.arr[right] > h.arr[largest] {
			largest = right
		}
		if largest != index {
			h.arr[index], h.arr[largest] = h.arr[largest], h.arr[index]
			index = largest
		} else {
			break
		}
	}
}
