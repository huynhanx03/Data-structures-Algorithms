pub struct SegmentTree {
    tree: Vec<i64>,
    n: usize,
}

impl SegmentTree {
    pub fn new(arr: &[i64]) -> Self {
        let n = arr.len();
        let mut st = Self {
            tree: vec![0; 4 * n],
            n,
        };
        if n > 0 {
            st.build(arr, 1, 0, n - 1);
        }
        st
    }

    fn build(&mut self, arr: &[i64], node: usize, start: usize, end: usize) {
        if start == end {
            self.tree[node] = arr[start];
            return;
        }
        let mid = start + (end - start) / 2;
        let left_node = 2 * node;
        let right_node = 2 * node + 1;
        self.build(arr, left_node, start, mid);
        self.build(arr, right_node, mid + 1, end);
        self.tree[node] = self.tree[left_node] + self.tree[right_node];
    }

    fn update_internal(&mut self, node: usize, start: usize, end: usize, idx: usize, val: i64) {
        if start == end {
            self.tree[node] = val;
            return;
        }
        let mid = start + (end - start) / 2;
        let left_node = 2 * node;
        let right_node = 2 * node + 1;
        if start <= idx && idx <= mid {
            self.update_internal(left_node, start, mid, idx, val);
        } else {
            self.update_internal(right_node, mid + 1, end, idx, val);
        }
        self.tree[node] = self.tree[left_node] + self.tree[right_node];
    }

    pub fn update(&mut self, idx: usize, val: i64) {
        if self.n > 0 {
            self.update_internal(1, 0, self.n - 1, idx, val);
        }
    }

    fn query_internal(&self, node: usize, start: usize, end: usize, l: usize, r: usize) -> i64 {
        if r < start || end < l {
            return 0;
        }
        if l <= start && end <= r {
            return self.tree[node];
        }
        let mid = start + (end - start) / 2;
        let left_node = 2 * node;
        let right_node = 2 * node + 1;
        let p1 = self.query_internal(left_node, start, mid, l, r);
        let p2 = self.query_internal(right_node, mid + 1, end, l, r);
        p1 + p2
    }

    pub fn query(&self, l: usize, r: usize) -> i64 {
        if self.n == 0 {
            return 0;
        }
        self.query_internal(1, 0, self.n - 1, l, r)
    }
}
