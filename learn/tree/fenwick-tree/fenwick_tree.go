type FenwickTree struct {
	bits []int64
}

func NewFenwickTree(n int) *FenwickTree {
	return &FenwickTree{
		bits: make([]int64, n+1),
	}
}

func lowbit(i int) int {
	return i & -i
}

func (ft *FenwickTree) Update(i int, x int64) {
	for i < len(ft.bits) {
		ft.bits[i] += x
		i += lowbit(i)
	}
}

func (ft *FenwickTree) Query(i int) int64 {
	var sum int64 = 0
	for i > 0 {
		sum += ft.bits[i]
		i -= lowbit(i)
	}
	return sum
}

func (ft *FenwickTree) QueryRange(l, r int) int64 {
	return ft.Query(r) - ft.Query(l-1)
}
