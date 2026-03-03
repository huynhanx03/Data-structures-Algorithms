/*
 Problem: 401. Binary Watch
 Language: rust
 Runtime: 0 ms (100.00%)
 Memory: 2.2 MB (29.76%)
 Tags: Backtracking, Bit Manipulation
*/
impl Solution {
    pub fn read_binary_watch(turned_on: i32) -> Vec<String> {
        let mut res = Vec::new();

        for h in 0..12i32 {
            for m in 0..60i32 {
                if (h.count_ones() + m.count_ones()) as i32 == turned_on {
                    res.push(format!("{}:{:02}", h, m));
                }
            }
        }

        res
    }
}