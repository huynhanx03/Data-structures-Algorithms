/*
 Problem: 767. Prime Number of Set Bits in Binary Representation
 Language: rust
 Runtime: 0 ms (100.00%)
 Memory: 2.1 MB (54.66%)
 Tags: Math, Bit Manipulation
*/
fn sieve(limit: usize) -> Vec<bool> {
    let mut prime = vec![true; limit + 1];
    if limit >= 0 { prime[0] = false; }
    if limit >= 1 { prime[1] = false; }

    let mut i = 2;
    while i * i <= limit {
        if prime[i] {
            let mut j = i * i;
            while j <= limit {
                prime[j] = false;
                j += i;
            }
        }
        i += 1;
    }
    prime
}

impl Solution {
    pub fn count_prime_set_bits(left: i32, right: i32) -> i32 {
        let primes = sieve(32);

        (left..=right)
            .filter(|&n| primes[n.count_ones() as usize])
            .count() as i32
    }
}
