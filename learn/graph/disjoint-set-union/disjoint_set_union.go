

type DisjointSetUnion struct {
	parent []int
	size   []int
}

func NewDisjointSetUnion(n int) *DisjointSetUnion {
	dsu := &DisjointSetUnion{
		parent: make([]int, n),
		size:   make([]int, n),
	}
	for i := 0; i < n; i++ {
		dsu.parent[i] = i
		dsu.size[i] = 1
	}
	return dsu
}

func (dsu *DisjointSetUnion) Find(v int) int {
	if v == dsu.parent[v] {
		return v
	}
	dsu.parent[v] = dsu.Find(dsu.parent[v])
	return dsu.parent[v]
}

func (dsu *DisjointSetUnion) Union(a, b int) {
	a = dsu.Find(a)
	b = dsu.Find(b)

	if a != b {
		if dsu.size[a] < dsu.size[b] {
			a, b = b, a
		}
		dsu.parent[b] = a
		dsu.size[a] += dsu.size[b]
	}
}
