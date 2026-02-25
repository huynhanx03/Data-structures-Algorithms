use std::collections::VecDeque;

pub struct BFSGraph {
    vertices: usize,
    adj_list: Vec<Vec<usize>>,
}

impl BFSGraph {
    pub fn new(vertices: usize) -> Self {
        BFSGraph {
            vertices,
            adj_list: vec![Vec::new(); vertices],
        }
    }

    pub fn add_edge(&mut self, src: usize, dest: usize) {
        self.adj_list[src].push(dest);
        self.adj_list[dest].push(src); // undirected
    }

    pub fn bfs(&self, start_vertex: usize) -> Vec<usize> {
        let mut visited = vec![false; self.vertices];
        let mut queue = VecDeque::new();
        let mut result = Vec::new();

        visited[start_vertex] = true;
        queue.push_back(start_vertex);

        while let Some(vertex) = queue.pop_front() {
            result.push(vertex);
            for &neighbor in &self.adj_list[vertex] {
                if !visited[neighbor] {
                    visited[neighbor] = true;
                    queue.push_back(neighbor);
                }
            }
        }
        result
    }
}
