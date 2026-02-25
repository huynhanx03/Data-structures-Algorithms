pub struct FenwickTree {
    bits: Vec<i64>,
}

impl FenwickTree {
    pub fn new(n: usize) -> Self {
        Self {
            bits: vec![0; n + 1],
        }
    }

    fn lowbit(i: usize) -> usize {
        i & !(i - 1)
    }

    pub fn update(&mut self, mut i: usize, x: i64) {
        while i < self.bits.len() {
            self.bits[i] += x;
            i += Self::lowbit(i);
        }
    }

    pub fn query(&self, mut i: usize) -> i64 {
        let mut sum = 0;
        while i > 0 {
            sum += self.bits[i];
            i -= Self::lowbit(i);
        }
        sum
    }

    pub fn query_range(&self, l: usize, r: usize) -> i64 {
        self.query(r) - self.query(l - 1)
    }
}
