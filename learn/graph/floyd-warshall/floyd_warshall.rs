pub struct FloydWarshall {
    pub vertices: usize,
    pub dist: Vec<Vec<i32>>,
}

impl FloydWarshall {
    pub fn new(vertices: usize) -> Self {
        let mut dist = vec![vec![i32::MAX; vertices]; vertices];
        for i in 0..vertices {
            dist[i][i] = 0;
        }
        FloydWarshall { vertices, dist }
    }

    pub fn add_edge(&mut self, u: usize, v: usize, weight: i32) {
        self.dist[u][v] = weight;
    }

    pub fn compute(&mut self) {
        let v_count = self.vertices;
        for k in 0..v_count {
            for i in 0..v_count {
                for j in 0..v_count {
                    if self.dist[i][k] != i32::MAX && self.dist[k][j] != i32::MAX {
                        let new_dist = self.dist[i][k] + self.dist[k][j];
                        if new_dist < self.dist[i][j] {
                            self.dist[i][j] = new_dist;
                        }
                    }
                }
            }
        }
    }
}
