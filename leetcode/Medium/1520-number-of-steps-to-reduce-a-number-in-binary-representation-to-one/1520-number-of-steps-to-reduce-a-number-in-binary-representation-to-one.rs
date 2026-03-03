/*
 Problem: 1520. Number of Steps to Reduce a Number in Binary Representation to One
 Language: rust
 Runtime: 0 ms (100.00%)
 Memory: 2.2 MB (12.33%)
 Tags: String, Bit Manipulation, Simulation
*/
impl Solution {
    pub fn num_steps(s: String) -> i32 {
        s.bytes().skip(1).rev().fold([0, 0], |[cnt, carry], b| {
            let is_odd = (b - b'0') as i32 + carry & 1;
            [cnt + 1 + is_odd, carry | is_odd]
        }).iter().sum()
    }
}