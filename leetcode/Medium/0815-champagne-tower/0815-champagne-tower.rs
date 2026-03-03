/*
 Problem: 815. Champagne Tower
 Language: rust
 Runtime: 1 ms (70.11%)
 Memory: 2.2 MB (81.68%)
 Tags: Dynamic Programming
*/
impl Solution {
    pub fn champagne_tower(poured: i32, query_row: i32, query_glass: i32) -> f64 {
        let mut dp = vec![0.0f64; query_row as usize + 2];
        dp[0] = poured as f64;
        
        for r in 0..query_row as usize {
            for c in (0..=r).rev() {
                let v = ((dp[c] - 1.0).max(0.0)) / 2.0;
                dp[c] = v;
                dp[c + 1] += v;
            }
        }

        dp[query_glass as usize].min(1.0)
    }
}