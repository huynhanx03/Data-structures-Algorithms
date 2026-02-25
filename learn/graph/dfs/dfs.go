

type DFSGraph struct {
	vertices int
	adjList  [][]int
}

func NewDFSGraph(v int) *DFSGraph {
	return &DFSGraph{
		vertices: v,
		adjList:  make([][]int, v),
	}
}

func (g *DFSGraph) AddEdge(src, dest int) {
	g.adjList[src] = append(g.adjList[src], dest)
	g.adjList[dest] = append(g.adjList[dest], src)
}

func (g *DFSGraph) DFS(startVertex int) []int {
	visited := make([]bool, g.vertices)
	var result []int
	g.dfsUtil(startVertex, visited, &result)
	return result
}

func (g *DFSGraph) dfsUtil(vertex int, visited []bool, result *[]int) {
	visited[vertex] = true
	*result = append(*result, vertex)

	for _, neighbor := range g.adjList[vertex] {
		if !visited[neighbor] {
			g.dfsUtil(neighbor, visited, result)
		}
	}
}
