pub struct LCA {
    up: Vec<Vec<usize>>,
    depth: Vec<usize>,
    log: usize,
}

impl LCA {
    pub fn new(n: usize, log: usize) -> Self {
        LCA {
            up: vec![vec![0; log]; n],
            depth: vec![0; n],
            log,
        }
    }

    pub fn dfs(&mut self, v: usize, p: usize, adj_list: &Vec<Vec<usize>>) {
        self.up[v][0] = p;
        if p != v {
            self.depth[v] = self.depth[p] + 1;
        }

        for i in 1..self.log {
            self.up[v][i] = self.up[self.up[v][i - 1]][i - 1];
        }

        for &u in &adj_list[v] {
            if u != p {
                self.dfs(u, v, adj_list);
            }
        }
    }

    pub fn get_lca(&self, mut u: usize, mut v: usize) -> usize {
        if self.depth[u] < self.depth[v] {
            std::mem::swap(&mut u, &mut v);
        }

        let k = self.depth[u] - self.depth[v];
        for i in (0..self.log).rev() {
            if (k & (1 << i)) != 0 {
                u = self.up[u][i];
            }
        }

        if u == v {
            return u;
        }

        for i in (0..self.log).rev() {
            if self.up[u][i] != self.up[v][i] {
                u = self.up[u][i];
                v = self.up[v][i];
            }
        }

        self.up[u][0]
    }
}
