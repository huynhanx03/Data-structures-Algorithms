

type MergeSort struct{}

func (s *MergeSort) Sort(arr []int) {
	if len(arr) > 0 {
		s.mergeSort(arr, 0, len(arr)-1)
	}
}

func (s *MergeSort) mergeSort(arr []int, left int, right int) {
	if left < right {
		mid := left + (right-left)/2
		s.mergeSort(arr, left, mid)
		s.mergeSort(arr, mid+1, right)
		s.merge(arr, left, mid, right)
	}
}

func (s *MergeSort) merge(arr []int, left int, mid int, right int) {
	n1 := mid - left + 1
	n2 := right - mid

	L := make([]int, n1)
	R := make([]int, n2)

	for i := 0; i < n1; i++ {
		L[i] = arr[left+i]
	}
	for j := 0; j < n2; j++ {
		R[j] = arr[mid+1+j]
	}

	i, j, k := 0, 0, left
	for i < n1 && j < n2 {
		if L[i] <= R[j] {
			arr[k] = L[i]
			i++
		} else {
			arr[k] = R[j]
			j++
		}
		k++
	}

	for i < n1 {
		arr[k] = L[i]
		i++
		k++
	}
	for j < n2 {
		arr[k] = R[j]
		j++
		k++
	}
}
