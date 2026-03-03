/*
 Problem: 763. Special Binary String
 Language: rust
 Runtime: 0 ms (100.00%)
 Memory: 2.2 MB (32.25%)
 Tags: String, Divide and Conquer, Sorting
*/
impl Solution {
    pub fn make_largest_special(s: String) -> String {
        let bytes = s.as_bytes();
        let mut cnt = 0;
        let mut l = 0;
        let mut blocks : Vec<String> = Vec::new();
        
        for i in 0..bytes.len() {
            cnt += if bytes[i] == b'1' { 1 } else { -1 };

            if cnt == 0 {
                let block = Self::make_largest_special(s[l+1..i].to_string());
                blocks.push(format!("1{}0", block));
                l = i + 1;
            }
        }

        blocks.sort_by(|a, b| b.cmp(a));

        blocks.concat()
    }
}