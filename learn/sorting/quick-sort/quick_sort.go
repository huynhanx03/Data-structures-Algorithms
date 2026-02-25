

type QuickSort struct{}

func (s *QuickSort) Sort(arr []int) {
	if len(arr) > 0 {
		s.quickSort(arr, 0, len(arr)-1)
	}
}

func (s *QuickSort) quickSort(arr []int, low, high int) {
	if low < high {
		pi := s.partition(arr, low, high)
		s.quickSort(arr, low, pi-1)
		s.quickSort(arr, pi+1, high)
	}
}

func (s *QuickSort) partition(arr []int, low, high int) int {
	pivot := arr[high]
	i := low - 1

	for j := low; j < high; j++ {
		if arr[j] < pivot {
			i++
			arr[i], arr[j] = arr[j], arr[i]
		}
	}
	arr[i+1], arr[high] = arr[high], arr[i+1]
	return i + 1
}
