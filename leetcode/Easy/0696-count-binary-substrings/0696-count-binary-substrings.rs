/*
 Problem: 696. Count Binary Substrings
 Language: rust
 Runtime: 0 ms (100.00%)
 Memory: 2.3 MB (69.23%)
 Tags: Two Pointers, String
*/
impl Solution {
    pub fn count_binary_substrings(s: String) -> i32 {
        let b = s.as_bytes();
        let (mut prev, mut curr, mut res) = (0, 1, 0);

        for i in 1..b.len() {
            if b[i] == b[i - 1] {
                curr += 1;
            } else {
                res += prev.min(curr);
                prev = curr;
                curr = 1;
            }
        }

        res + prev.min(curr)
    }
}