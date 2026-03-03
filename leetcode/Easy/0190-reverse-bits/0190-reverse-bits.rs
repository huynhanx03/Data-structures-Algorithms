/*
 Problem: 190. Reverse Bits
 Language: rust
 Runtime: 2 ms (52.47%)
 Memory: 2.1 MB (92.52%)
 Tags: Divide and Conquer, Bit Manipulation
*/
impl Solution {
    pub fn reverse_bits(n: i32) -> i32 {
        let mut v: i32 = 0;
        let mut x = n;

        for _ in 0..32 {
            v = (v << 1) | (x & 1);
            x >>= 1;
        }

        v   
    }
}