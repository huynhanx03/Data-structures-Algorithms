pub struct BFEdge {
    pub u: usize,
    pub v: usize,
    pub weight: i32,
}

pub struct BellmanFord {
    pub vertices: usize,
    pub edges: Vec<BFEdge>,
}

impl BellmanFord {
    pub fn new(vertices: usize) -> Self {
        BellmanFord {
            vertices,
            edges: Vec::new(),
        }
    }

    pub fn add_edge(&mut self, u: usize, v: usize, weight: i32) {
        self.edges.push(BFEdge { u, v, weight });
    }

    pub fn shortest_path(&self, start: usize) -> Option<Vec<i32>> {
        let mut dist: Vec<_> = (0..self.vertices).map(|_| i32::MAX).collect();
        dist[start] = 0;

        for _ in 1..self.vertices {
            for edge in &self.edges {
                if dist[edge.u] != i32::MAX && dist[edge.u] + edge.weight < dist[edge.v] {
                    dist[edge.v] = dist[edge.u] + edge.weight;
                }
            }
        }

        for edge in &self.edges {
            if dist[edge.u] != i32::MAX && dist[edge.u] + edge.weight < dist[edge.v] {
                return None; // Negative weight cycle
            }
        }

        Some(dist)
    }
}
