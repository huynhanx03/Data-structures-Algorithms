use std::cmp::Reverse;
use std::collections::{BinaryHeap, HashMap};
use std::io::{self, Read};

struct Sliding {
    left: BinaryHeap<i64>,
    right: BinaryHeap<Reverse<i64>>,
    pending: HashMap<i64, i64>,
    left_size: usize,
    right_size: usize,
    left_sum: i64,
    right_sum: i64,
}

impl Sliding {
    fn new() -> Self {
        Self {
            left: BinaryHeap::new(),
            right: BinaryHeap::new(),
            pending: HashMap::new(),
            left_size: 0,
            right_size: 0,
            left_sum: 0,
            right_sum: 0,
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
        while self.left_size > self.right_size + 1 {
            self.prune();
            if let Some(x) = self.left.pop() {
                self.right.push(Reverse(x));
                self.left_size -= 1;
                self.left_sum -= x;
                self.right_size += 1;
                self.right_sum += x;
            }
        }

        while self.right_size > self.left_size {
            self.prune();
            if let Some(Reverse(x)) = self.right.pop() {
                self.left.push(x);
                self.right_size -= 1;
                self.right_sum -= x;
                self.left_size += 1;
                self.left_sum += x;
            }
        }
    }

    fn push(&mut self, x: i64) {
        self.prune();
        let median = self.left.peek().copied().unwrap_or(x);

        if x <= median {
            self.left.push(x);
            self.left_size += 1;
            self.left_sum += x;
        } else {
            self.right.push(Reverse(x));
            self.right_size += 1;
            self.right_sum += x;
        }
        self.balance();
    }

    fn pop(&mut self, x: i64) {
        self.prune();
        let median = self.left.peek().copied();

        if let Some(m) = median {
            if x <= m {
                self.left_size -= 1;
                self.left_sum -= x;
            } else {
                self.right_size -= 1;
                self.right_sum -= x;
            }
        } else {
            self.left_size = self.left_size.saturating_sub(1);
        }

        *self.pending.entry(x).or_insert(0) += 1;
        self.balance();
    }

    fn median(&mut self) -> i64 {
        *self.left.peek().unwrap()
    }

    fn get(&mut self) -> i64 {
        self.prune();

        let m = self.median();

        let left_cost  = m * self.left_size as i64 - self.left_sum;
        let right_cost = self.right_sum - m * self.right_size as i64;

        left_cost + right_cost
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
            print!("{} ", s.get());
        }
    }
}

