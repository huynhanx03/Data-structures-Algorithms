use std::cmp::Ordering;
use std::collections::BinaryHeap;

#[derive(Copy, Clone, Eq, PartialEq)]
pub struct PrimState {
    pub cost: i32,
    pub position: usize,
}

impl Ord for PrimState {
    fn cmp(&self, other: &Self) -> Ordering {
        other
            .cost
            .cmp(&self.cost)
            .then_with(|| self.position.cmp(&other.position))
    }
}

impl PartialOrd for PrimState {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

pub struct PrimEdge {
    pub to: usize,
    pub weight: i32,
}

pub struct Prim {
    pub vertices: usize,
    pub adj_list: Vec<Vec<PrimEdge>>,
}

impl Prim {
    pub fn new(vertices: usize) -> Self {
        Prim {
            vertices,
            adj_list: (0..vertices).map(|_| Vec::new()).collect(),
        }
    }

    pub fn add_edge(&mut self, u: usize, v: usize, weight: i32) {
        self.adj_list[u].push(PrimEdge { to: v, weight });
        self.adj_list[v].push(PrimEdge { to: u, weight });
    }

    pub fn mst(&self) -> i32 {
        let mut key: Vec<_> = (0..self.vertices).map(|_| i32::MAX).collect();
        let mut in_mst = vec![false; self.vertices];

        let mut heap = BinaryHeap::new();

        key[0] = 0;
        heap.push(PrimState {
            cost: 0,
            position: 0,
        });

        let mut mst_weight = 0;

        while let Some(PrimState { cost, position }) = heap.pop() {
            if in_mst[position] {
                continue;
            }

            in_mst[position] = true;
            mst_weight += cost;

            for edge in &self.adj_list[position] {
                if !in_mst[edge.to] && edge.weight < key[edge.to] {
                    key[edge.to] = edge.weight;
                    heap.push(PrimState {
                        cost: edge.weight,
                        position: edge.to,
                    });
                }
            }
        }

        mst_weight
    }
}
