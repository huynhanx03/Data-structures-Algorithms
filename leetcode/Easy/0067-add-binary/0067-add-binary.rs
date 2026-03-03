/*
 Problem: 67. Add Binary
 Language: rust
 Runtime: 0 ms (100.00%)
 Memory: 2.2 MB (16.32%)
 Tags: Math, String, Bit Manipulation, Simulation
*/
impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        let bytes_a = a.as_bytes();
        let bytes_b = b.as_bytes();

        let mut i: i32 = bytes_a.len() as i32 - 1;
        let mut j: i32 = bytes_b.len() as i32 - 1;

        let mut carry = 0;
        let mut result: Vec<char> = Vec::new();

        while i >= 0 || j >= 0 || carry > 0 {
            let mut sum = carry;

            if i >= 0 {
                sum += (bytes_a[i as usize] - b'0') as i32;
                i -= 1;
            }

            if j >= 0 {
                sum += (bytes_b[j as usize] - b'0') as i32;
                j -= 1;
            }

            result.push(char::from(b'0' + (sum % 2) as u8));
            carry = sum / 2;
        }

        result.iter().rev().collect()
    }
}
