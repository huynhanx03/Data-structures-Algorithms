type SegmentTree struct {
	tree []int64
	n    int
}

func NewSegmentTree(arr []int64) *SegmentTree {
	n := len(arr)
	st := &SegmentTree{
		tree: make([]int64, 4*n),
		n:    n,
	}
	st.build(arr, 1, 0, n-1)
	return st
}

func (st *SegmentTree) build(arr []int64, node, start, end int) {
	if start == end {
		st.tree[node] = arr[start]
		return
	}
	mid := start + (end-start)/2
	leftNode, rightNode := 2*node, 2*node+1
	st.build(arr, leftNode, start, mid)
	st.build(arr, rightNode, mid+1, end)
	st.tree[node] = st.tree[leftNode] + st.tree[rightNode]
}

func (st *SegmentTree) update(node, start, end, idx int, val int64) {
	if start == end {
		st.tree[node] = val
		return
	}
	mid := start + (end-start)/2
	leftNode, rightNode := 2*node, 2*node+1
	if start <= idx && idx <= mid {
		st.update(leftNode, start, mid, idx, val)
	} else {
		st.update(rightNode, mid+1, end, idx, val)
	}
	st.tree[node] = st.tree[leftNode] + st.tree[rightNode]
}

func (st *SegmentTree) Update(idx int, val int64) {
	st.update(1, 0, st.n-1, idx, val)
}

func (st *SegmentTree) query(node, start, end, l, r int) int64 {
	if r < start || end < l {
		return 0
	}
	if l <= start && end <= r {
		return st.tree[node]
	}
	mid := start + (end-start)/2
	leftNode, rightNode := 2*node, 2*node+1
	p1 := st.query(leftNode, start, mid, l, r)
	p2 := st.query(rightNode, mid+1, end, l, r)
	return p1 + p2
}

func (st *SegmentTree) Query(l, r int) int64 {
	return st.query(1, 0, st.n-1, l, r)
}
