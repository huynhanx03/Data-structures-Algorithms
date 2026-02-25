

import "math"

type BFEdge struct {
	u      int
	v      int
	weight int
}

type BellmanFord struct {
	vertices int
	edges    []BFEdge
}

func NewBellmanFord(v int) *BellmanFord {
	return &BellmanFord{
		vertices: v,
		edges:    []BFEdge{},
	}
}

func (bf *BellmanFord) AddEdge(u, v, weight int) {
	bf.edges = append(bf.edges, BFEdge{u, v, weight})
}

func (bf *BellmanFord) ShortestPath(start int) ([]int, bool) {
	dist := make([]int, bf.vertices)
	for i := range dist {
		dist[i] = math.MaxInt32
	}
	dist[start] = 0

	for i := 1; i < bf.vertices; i++ {
		for _, edge := range bf.edges {
			if dist[edge.u] != math.MaxInt32 && dist[edge.u]+edge.weight < dist[edge.v] {
				dist[edge.v] = dist[edge.u] + edge.weight
			}
		}
	}

	for _, edge := range bf.edges {
		if dist[edge.u] != math.MaxInt32 && dist[edge.u]+edge.weight < dist[edge.v] {
			return nil, false // Negative cycle detected
		}
	}

	return dist, true
}
