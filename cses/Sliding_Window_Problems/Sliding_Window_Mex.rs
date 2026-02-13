use std::collections::{BTreeSet, HashMap};
use std::io::{self, Read};

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

    let mut cnt: HashMap<i64, i64> = HashMap::new();
    let mut set: BTreeSet<i64> = (0..=k as i64).collect();

    for i in 0..n {
        *cnt.entry(v[i]).or_insert(0) += 1;
        set.remove(&v[i]);

        if i >= k {
            *cnt.entry(v[i - k]).or_insert(0) -= 1;
            if *cnt.get(&v[i - k]).unwrap() == 0 {
                cnt.remove(&v[i - k]);
                set.insert(v[i - k]);
            }
        }

        if i >= k - 1 {
            print!("{} ", *set.iter().next().unwrap());
        }
    }
}

