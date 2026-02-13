use std::io::{self, Read};

struct Fenwick {
    bits: Vec<i64>,
}

impl Fenwick {
    fn new(n: usize) -> Self {
        Self {
            bits: vec![0; n + 1],
        }
    }

    fn lowbit(i: usize) -> usize {
        i & !(i - 1)
    }

    fn update(&mut self, mut i: usize, x: i64) {
        while i < self.bits.len() {
            self.bits[i] += x;
            i += Self::lowbit(i);
        }
    }

    fn query(&self, mut i: usize) -> i64 {
        let mut sum = 0;
        while i > 0 {
            sum += self.bits[i];
            i -= Self::lowbit(i);
        }
        sum
    }

    fn range(&self, l: usize, r: usize) -> i64 {
        self.query(r) - self.query(l - 1)
    }
}

fn main() {
    let mut input = String::new();
    if io::stdin().read_to_string(&mut input).is_err() {
        return;
    }
    let mut scanner = input.split_whitespace();

    let n: usize = scanner.next().unwrap().parse().unwrap();
    let k: usize = scanner.next().unwrap().parse().unwrap();

    let mut v: Vec<i64> = Vec::new();
    for _ in 0..n {
        v.push(scanner.next().unwrap().parse().unwrap());
    }

    let mut vals = v.clone();
    vals.sort();
    vals.dedup();

    let get_id = |x: i64| vals.binary_search(&x).unwrap();

    let mut bit = Fenwick::new(vals.len() + 1);
    let mut inv: i64 = 0;

    for i in 0..n {
        let x_idx = get_id(v[i]) + 1;

        inv += bit.range(x_idx + 1, vals.len());
        bit.update(x_idx, 1);

        if i >= k {
            let y_idx = get_id(v[i - k]) + 1;
            bit.update(y_idx, -1);
            inv -= bit.query(y_idx - 1);
        }

        if i >= k - 1 {
            print!("{} ", inv);
        }
    }
}

