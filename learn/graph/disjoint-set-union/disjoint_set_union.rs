pub struct DisjointSetUnion {
    parent: Vec<usize>,
    size: Vec<usize>,
}

impl DisjointSetUnion {
    pub fn new(n: usize) -> Self {
        let parent: Vec<usize> = (0..n).collect();
        let size = vec![1; n];
        DisjointSetUnion { parent, size }
    }

    pub fn find(&mut self, v: usize) -> usize {
        if v == self.parent[v] {
            return v;
        }
        self.parent[v] = self.find(self.parent[v]);
        self.parent[v]
    }

    pub fn union(&mut self, mut a: usize, mut b: usize) {
        a = self.find(a);
        b = self.find(b);

        if a != b {
            if self.size[a] < self.size[b] {
                std::mem::swap(&mut a, &mut b);
            }
            self.parent[b] = a;
            self.size[a] += self.size[b];
        }
    }
}
