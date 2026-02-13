use std::io::{self, Read};

struct Queue {
    s_in: Vec<(i64, i64)>,
    s_out: Vec<(i64, i64)>,
}

impl Queue {
    fn new() -> Self {
        Self {
            s_in: Vec::new(),
            s_out: Vec::new(),
        }
    }

    fn push(&mut self, x: i64) {
        let agg = if self.s_in.is_empty() {
            x
        } else {
            self.s_in.last().unwrap().1 | x
        };
        self.s_in.push((x, agg));
    }

    fn pop(&mut self) {
        if self.s_out.is_empty() {
            while let Some((val, _)) = self.s_in.pop() {
                let agg = if self.s_out.is_empty() {
                    val
                } else {
                    self.s_out.last().unwrap().1 | val
                };
                self.s_out.push((val, agg));
            }
        }
        self.s_out.pop();
    }

    fn query(&self) -> i64 {
        let sum_in = if let Some(last) = self.s_in.last() {
            last.1
        } else {
            0
        };
        let sum_out = if let Some(last) = self.s_out.last() {
            last.1
        } else {
            0
        };
        sum_in | sum_out
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

    let mut x: i64 = scanner.next().unwrap().parse().unwrap();
    let a: i64 = scanner.next().unwrap().parse().unwrap();
    let b: i64 = scanner.next().unwrap().parse().unwrap();
    let c: i64 = scanner.next().unwrap().parse().unwrap();

    let mut res: i64 = 0;

    let mut q = Queue::new();

    for i in 0..n {
        q.push(x);

        if i >= k {
            q.pop();
        }

        if i >= k - 1 {
            let sum = q.query();
            res ^= sum;
        }

        x = (a * x + b) % c;
    }

    println!("{}", res);
}

