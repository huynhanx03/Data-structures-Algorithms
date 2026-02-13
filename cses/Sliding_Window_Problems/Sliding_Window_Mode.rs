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
    let mut set: BTreeSet<(i64, i64)> = BTreeSet::new();

    for i in 0..n {
        if i >= k {
            let old_val = v[i - k];
            let old_cnt = *cnt.get(&old_val).unwrap();
            set.remove(&(-old_cnt, old_val));
            if old_cnt == 1 {
                cnt.remove(&old_val);
            } else {
                cnt.insert(old_val, old_cnt - 1);
                set.insert((-(old_cnt - 1), old_val));
            }
        }

        let val = v[i];
        let old_cnt = *cnt.get(&val).unwrap_or(&0);
        if old_cnt > 0 {
            set.remove(&(-old_cnt, val));
        }
        cnt.insert(val, old_cnt + 1);
        set.insert((-(old_cnt + 1), val));

        if i >= k - 1 {
            print!("{} ", set.iter().next().unwrap().1);
        }
    }
}

