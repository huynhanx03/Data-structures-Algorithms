

import (
	"container/heap"
	"math"
)

type Edge struct {
	to     int
	weight int
}

type Item struct {
	vertex int
	dist   int
	index  int
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].dist < pq[j].dist
}
func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}
func (pq *PriorityQueue) Push(x interface{}) {
	n := len(*pq)
	item := x.(*Item)
	item.index = n
	*pq = append(*pq, item)
}
func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	item.index = -1
	*pq = old[0 : n-1]
	return item
}

type Dijkstra struct {
	vertices int
	adjList  [][]Edge
}

func NewDijkstra(v int) *Dijkstra {
	return &Dijkstra{
		vertices: v,
		adjList:  make([][]Edge, v),
	}
}

func (d *Dijkstra) AddEdge(u, v, weight int) {
	d.adjList[u] = append(d.adjList[u], Edge{to: v, weight: weight})
	d.adjList[v] = append(d.adjList[v], Edge{to: u, weight: weight}) // if undirected
}

func (d *Dijkstra) ShortestPath(start int) []int {
	dist := make([]int, d.vertices)
	for i := range dist {
		dist[i] = math.MaxInt32
	}
	dist[start] = 0

	pq := make(PriorityQueue, 0)
	heap.Init(&pq)
	heap.Push(&pq, &Item{vertex: start, dist: 0})

	for pq.Len() > 0 {
		item := heap.Pop(&pq).(*Item)
		u := item.vertex

		if item.dist > dist[u] {
			continue
		}

		for _, edge := range d.adjList[u] {
			v := edge.to
			weight := edge.weight

			if dist[u]+weight < dist[v] {
				dist[v] = dist[u] + weight
				heap.Push(&pq, &Item{vertex: v, dist: dist[v]})
			}
		}
	}

	return dist
}
