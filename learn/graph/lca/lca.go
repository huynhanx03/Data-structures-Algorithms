

type LCA struct {
	up    [][]int
	depth []int
	log   int
}

func NewLCA(n int, log int) *LCA {
	up := make([][]int, n)
	for i := range up {
		up[i] = make([]int, log)
	}
	return &LCA{
		up:    up,
		depth: make([]int, n),
		log:   log,
	}
}

func (lca *LCA) Dfs(v int, p int, adjList [][]int) {
	lca.up[v][0] = p
	if p != v {
		lca.depth[v] = lca.depth[p] + 1
	}

	for i := 1; i < lca.log; i++ {
		lca.up[v][i] = lca.up[lca.up[v][i-1]][i-1]
	}

	for _, u := range adjList[v] {
		if u != p {
			lca.Dfs(u, v, adjList)
		}
	}
}

func (lca *LCA) GetLCA(u, v int) int {
	if lca.depth[u] < lca.depth[v] {
		u, v = v, u
	}

	k := lca.depth[u] - lca.depth[v]
	for i := lca.log - 1; i >= 0; i-- {
		if (k & (1 << i)) != 0 {
			u = lca.up[u][i]
		}
	}

	if u == v {
		return u
	}

	for i := lca.log - 1; i >= 0; i-- {
		if lca.up[u][i] != lca.up[v][i] {
			u = lca.up[u][i]
			v = lca.up[v][i]
		}
	}

	return lca.up[u][0]
}
