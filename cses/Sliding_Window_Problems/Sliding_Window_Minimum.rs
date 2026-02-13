use std::collections::VecDeque;
use std::io::{self, Read};

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

    let mut dq: VecDeque<(usize, i64)> = VecDeque::new();
    let mut res: i64 = 0;

    for i in 0..n {
        while let Some(&(idx, _)) = dq.front() {
            if idx + k <= i {
                dq.pop_front();
            } else {
                break;
            }
        }

        while let Some(&(_, val)) = dq.back() {
            if val >= x {
                dq.pop_back();
            } else {
                break;
            }
        }

        dq.push_back((i, x));

        if i >= k - 1 {
            res ^= dq.front().unwrap().1;
        }

        x = (a * x + b) % c;
    }

    println!("{}", res);
}

