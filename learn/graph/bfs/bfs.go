

import "container/list"

type BFSGraph struct {
	vertices int
	adjList  [][]int
}

func NewBFSGraph(v int) *BFSGraph {
	return &BFSGraph{
		vertices: v,
		adjList:  make([][]int, v),
	}
}

func (g *BFSGraph) AddEdge(src, dest int) {
	g.adjList[src] = append(g.adjList[src], dest)
	g.adjList[dest] = append(g.adjList[dest], src)
}

func (g *BFSGraph) BFS(startVertex int) []int {
	visited := make([]bool, g.vertices)
	queue := list.New()
	var result []int

	visited[startVertex] = true
	queue.PushBack(startVertex)

	for queue.Len() > 0 {
		element := queue.Front()
		vertex := element.Value.(int)
		result = append(result, vertex)
		queue.Remove(element)

		for _, neighbor := range g.adjList[vertex] {
			if !visited[neighbor] {
				visited[neighbor] = true
				queue.PushBack(neighbor)
			}
		}
	}
	return result
}
