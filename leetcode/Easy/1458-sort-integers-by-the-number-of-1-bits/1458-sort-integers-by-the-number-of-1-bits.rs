/*
 Problem: 1458. Sort Integers by The Number of 1 Bits
 Language: rust
 Runtime: 0 ms (100.00%)
 Memory: 2.2 MB (81.22%)
 Tags: Array, Bit Manipulation, Sorting, Counting
*/
impl Solution {
    pub fn sort_by_bits(mut arr: Vec<i32>) -> Vec<i32> {
        arr.sort_by_key(|&x| (x.count_ones(), x));
        arr
    }
}