pub struct DFSGraph {
    vertices: usize,
    adj_list: Vec<Vec<usize>>,
}

impl DFSGraph {
    pub fn new(vertices: usize) -> Self {
        DFSGraph {
            vertices,
            adj_list: vec![Vec::new(); vertices],
        }
    }

    pub fn add_edge(&mut self, src: usize, dest: usize) {
        self.adj_list[src].push(dest);
        self.adj_list[dest].push(src); // undirected
    }

    pub fn dfs(&self, start_vertex: usize) -> Vec<usize> {
        let mut visited = vec![false; self.vertices];
        let mut result = Vec::new();
        self.dfs_util(start_vertex, &mut visited, &mut result);
        result
    }

    fn dfs_util(&self, vertex: usize, visited: &mut Vec<bool>, result: &mut Vec<usize>) {
        visited[vertex] = true;
        result.push(vertex);

        for &neighbor in &self.adj_list[vertex] {
            if !visited[neighbor] {
                self.dfs_util(neighbor, visited, result);
            }
        }
    }
}
