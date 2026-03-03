/*
 Problem: 1557. Check If a String Contains All Binary Codes of Size K
 Language: rust
 Runtime: 45 ms (42.22%)
 Memory: 11.4 MB (38.00%)
 Tags: Hash Table, String, Bit Manipulation, Rolling Hash, Hash Function
*/
use std::collections::HashSet;

impl Solution {
    pub fn has_all_codes(s: String, k: i32) -> bool {
        let k = k as usize;
        let bytes = s.as_bytes();
        let limit = 1usize << k;
        let mut seen = HashSet::new();
        let mut mask = 0usize;

        for i in 0..bytes.len() {
            mask = ((mask << 1) & (limit - 1)) | (bytes[i] - b'0') as usize;
            if i + 1 >= k {
                seen.insert(mask);
            }
        }

        return seen.len() as usize == limit
    }
}