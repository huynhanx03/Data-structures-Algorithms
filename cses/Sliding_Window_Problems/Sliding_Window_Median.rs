use std::cmp::Reverse;
use std::collections::{BinaryHeap, HashMap};
use std::io::{self, Read};

struct Sliding {
    left: BinaryHeap<i64>,
    right: BinaryHeap<Reverse<i64>>,
    pending: HashMap<i64, i64>,
    left_sz: usize,
    right_sz: usize,
}

impl Sliding {
    fn new() -> Self {
        Self {
            left: BinaryHeap::new(),
            right: BinaryHeap::new(),
            pending: HashMap::new(),
            left_sz: 0,
            right_sz: 0,
        }
    }

    fn prune(&mut self) {
        while let Some(&x) = self.left.peek() {
            if let Some(c) = self.pending.get_mut(&x) {
                if *c > 0 {
                    *c -= 1;
                    if *c == 0 {
                        self.pending.remove(&x);
                    }
                    self.left.pop();
                } else {
                    break;
                }
            } else {
                break;
            }
        }

        while let Some(&Reverse(x)) = self.right.peek() {
            if let Some(c) = self.pending.get_mut(&x) {
                if *c > 0 {
                    *c -= 1;
                    if *c == 0 {
                        self.pending.remove(&x);
                    }
                    self.right.pop();
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }

    fn balance(&mut self) {
        while self.left_sz > self.right_sz + 1 {
            self.prune();
            if let Some(x) = self.left.pop() {
                self.right.push(Reverse(x));
                self.left_sz -= 1;
                self.right_sz += 1;
            }
        }
        
        while self.right_sz > self.left_sz {
            self.prune();
            if let Some(Reverse(x)) = self.right.pop() {
                self.left.push(x);
                self.right_sz -= 1;
                self.left_sz += 1;
            }
        }
    }

    fn push(&mut self, x: i64) {
        self.prune();
        let median = self.left.peek().copied().unwrap_or(x);

        if x <= median {
            self.left.push(x);
            self.left_sz += 1;
        } else {
            self.right.push(Reverse(x));
            self.right_sz += 1;
        }
        self.balance();
    }

    fn pop(&mut self, x: i64) {
        self.prune();
        let median = self.left.peek().copied();

        if let Some(m) = median {
            if x <= m {
                self.left_sz -= 1;
            } else {
                self.right_sz -= 1;
            }
        } else {
            self.left_sz = self.left_sz.saturating_sub(1);
        }

        *self.pending.entry(x).or_insert(0) += 1;
        self.balance();
    }

    fn median(&mut self) -> i64 {
        self.prune();
        *self.left.peek().unwrap()
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

    let mut s = Sliding::new();

    for i in 0..n {
        s.push(v[i]);

        if i >= k {
            s.pop(v[i - k]);
        }

        if i >= k - 1 {
            print!("{} ", s.median());
        }
    }
}

