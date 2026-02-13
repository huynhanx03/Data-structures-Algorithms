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

    let mut buf = vec![0; k];
    let mut sum: i64 = 0;
    let mut res: i64 = 0;

    for i in 0..n {
        let idx = (i as usize) % k;

        if i >= k {
            sum ^= buf[idx];
        }

        buf[idx] = x;
        sum ^= x;

        if i >= k - 1 {
            res ^= sum;
        }

        x = (a * x + b) % c;
    }

    println!("{}", res);
}
