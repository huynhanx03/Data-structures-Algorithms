

type LinearSearch struct{}

func (s *LinearSearch) Search(arr []int, target int) int {
	for i, v := range arr {
		if v == target {
			return i
		}
	}
	return -1
}
