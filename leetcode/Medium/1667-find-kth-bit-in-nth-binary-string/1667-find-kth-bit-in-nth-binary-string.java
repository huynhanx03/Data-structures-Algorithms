/*
 Problem: 1667. Find Kth Bit in Nth Binary String
 Language: java
 Runtime: 0 ms (100.00%)
 Memory: 42.5 MB (87.38%)
 Tags: String, Recursion, Simulation
*/
class Solution {
    public char findKthBit(int n, int k) {
        if (n == 1) return '0';
        
        int mid = 1 << (n - 1);
        
        if (k == mid) return '1';
        
        if (k < mid)
            return findKthBit(n - 1, k);
        
        char res = findKthBit(n - 1, (1 << n) - k);
        return res == '0' ? '1' : '0';
    }
}