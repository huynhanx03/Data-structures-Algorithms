/*
 Problem: 899. Binary Gap
 Language: rust
 Runtime: 0 ms (100.00%)
 Memory: 2.1 MB (46.76%)
 Tags: Bit Manipulation
*/
impl Solution {
    pub fn binary_gap(n: i32) -> i32 {
        let mut n = n;
        let mut pos = 0;
        let mut last = -1;
        let mut ans = 0;

        while n > 0 {
            if (n & 1) == 1 {
                if last != -1 {
                    ans = ans.max(pos - last);
                }
                last = pos;
            }
            pos += 1;
            n >>= 1;
        }

        ans
    }
}
