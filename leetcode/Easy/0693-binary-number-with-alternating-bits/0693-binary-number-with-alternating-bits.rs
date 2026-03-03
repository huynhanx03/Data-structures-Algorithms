/*
 Problem: 693. Binary Number with Alternating Bits
 Language: rust
 Runtime: 0 ms (100.00%)
 Memory: 2 MB (90.01%)
 Tags: Bit Manipulation
*/
impl Solution {
    pub fn has_alternating_bits(n: i32) -> bool {
        let mut v = n;
        let mut r =  v % 2;
        v /= 2;
        while v > 0 {
            if v % 2 == r {
                return false;
            }

            r = v % 2;
            v /= 2;
        }

        true
    }
}