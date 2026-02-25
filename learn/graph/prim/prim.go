

import (
	"container/heap"
	"math"
)

type PrimEdge struct {
	to     int
	weight int
}

type PrimItem struct {
	vertex int
	weight int
	index  int
}

type PrimPQ []*PrimItem

func (pq PrimPQ) Len() int           { return len(pq) }
func (pq PrimPQ) Less(i, j int) bool { return pq[i].weight < pq[j].weight }
func (pq PrimPQ) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}
func (pq *PrimPQ) Push(x interface{}) {
	n := len(*pq)
	item := x.(*PrimItem)
	item.index = n
	*pq = append(*pq, item)
}
func (pq *PrimPQ) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	item.index = -1
	*pq = old[0 : n-1]
	return item
}

type Prim struct {
	vertices int
	adjList  [][]PrimEdge
}

func NewPrim(v int) *Prim {
	return &Prim{
		vertices: v,
		adjList:  make([][]PrimEdge, v),
	}
}

func (p *Prim) AddEdge(u, v, weight int) {
	p.adjList[u] = append(p.adjList[u], PrimEdge{to: v, weight: weight})
	p.adjList[v] = append(p.adjList[v], PrimEdge{to: u, weight: weight})
}

func (p *Prim) MST() int {
	key := make([]int, p.vertices)
	inMST := make([]bool, p.vertices)

	for i := range key {
		key[i] = math.MaxInt32
	}
	key[0] = 0

	pq := make(PrimPQ, 0)
	heap.Init(&pq)
	heap.Push(&pq, &PrimItem{vertex: 0, weight: 0})

	mstWeight := 0

	for pq.Len() > 0 {
		item := heap.Pop(&pq).(*PrimItem)
		u := item.vertex

		if inMST[u] {
			continue
		}

		inMST[u] = true
		mstWeight += item.weight

		for _, edge := range p.adjList[u] {
			v := edge.to
			weight := edge.weight

			if !inMST[v] && key[v] > weight {
				key[v] = weight
				heap.Push(&pq, &PrimItem{vertex: v, weight: key[v]})
			}
		}
	}

	return mstWeight
}
