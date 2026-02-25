

import "math"

type FloydWarshall struct {
	vertices int
	dist     [][]int
}

func NewFloydWarshall(v int) *FloydWarshall {
	fw := &FloydWarshall{
		vertices: v,
		dist:     make([][]int, v),
	}
	for i := 0; i < v; i++ {
		fw.dist[i] = make([]int, v)
		for j := 0; j < v; j++ {
			if i == j {
				fw.dist[i][j] = 0
			} else {
				fw.dist[i][j] = math.MaxInt32
			}
		}
	}
	return fw
}

func (fw *FloydWarshall) AddEdge(u, v, weight int) {
	fw.dist[u][v] = weight
}

func (fw *FloydWarshall) Compute() {
	v := fw.vertices
	for k := 0; k < v; k++ {
		for i := 0; i < v; i++ {
			for j := 0; j < v; j++ {
				if fw.dist[i][k] != math.MaxInt32 && fw.dist[k][j] != math.MaxInt32 && fw.dist[i][k]+fw.dist[k][j] < fw.dist[i][j] {
					fw.dist[i][j] = fw.dist[i][k] + fw.dist[k][j]
				}
			}
		}
	}
}

func (fw *FloydWarshall) GetDist() [][]int {
	return fw.dist
}
