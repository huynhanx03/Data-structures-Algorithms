use std::cmp::Ordering;
use std::collections::BinaryHeap;

#[derive(Copy, Clone, Eq, PartialEq)]
pub struct State {
    cost: i32,
    position: usize,
}

impl Ord for State {
    fn cmp(&self, other: &Self) -> Ordering {
        // Reverse order because BinaryHeap is a max-heap
        other
            .cost
            .cmp(&self.cost)
            .then_with(|| self.position.cmp(&other.position))
    }
}

impl PartialOrd for State {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

pub struct Edge {
    pub to: usize,
    pub weight: i32,
}

pub struct Dijkstra {
    pub vertices: usize,
    pub adj_list: Vec<Vec<Edge>>,
}

impl Dijkstra {
    pub fn new(vertices: usize) -> Self {
        Dijkstra {
            vertices,
            adj_list: (0..vertices).map(|_| Vec::new()).collect(),
        }
    }

    pub fn add_edge(&mut self, u: usize, v: usize, weight: i32) {
        self.adj_list[u].push(Edge { to: v, weight });
        self.adj_list[v].push(Edge { to: u, weight });
    }

    pub fn shortest_path(&self, start: usize) -> Vec<i32> {
        let mut dist: Vec<_> = (0..self.vertices).map(|_| i32::MAX).collect();

        let mut heap = BinaryHeap::new();

        dist[start] = 0;
        heap.push(State {
            cost: 0,
            position: start,
        });

        while let Some(State { cost, position }) = heap.pop() {
            if cost > dist[position] {
                continue;
            }

            for edge in &self.adj_list[position] {
                let next = State {
                    cost: cost + edge.weight,
                    position: edge.to,
                };

                if next.cost < dist[next.position] {
                    heap.push(next);
                    dist[next.position] = next.cost;
                }
            }
        }

        dist
    }
}
