"""
 Problem: 1667. Find Kth Bit in Nth Binary String
 Language: python3
 Runtime: 0 ms (100.00%)
 Memory: 19.2 MB (94.49%)
 Tags: String, Recursion, Simulation
"""
class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        if n == 1:
            return "0"
        
        mid = 1 << (n - 1)
        
        if k == mid:
            return "1"
        
        if k < mid:
            return self.findKthBit(n - 1, k)
        
        res = self.findKthBit(n - 1, (1 << n) - k)
        return "1" if res == "0" else "0"