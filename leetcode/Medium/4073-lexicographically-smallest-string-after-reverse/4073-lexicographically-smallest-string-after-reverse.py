"""
 Problem: 4073. Lexicographically Smallest String After Reverse
 Language: python3
 Runtime: 111 ms (12.58%)
 Memory: 17.9 MB (96.86%)
 Tags: Two Pointers, Binary Search, Enumeration
"""
class Solution:
    def lexSmallest(self, s: str) -> str:
        n = len(s)
        res = s
        
        for k in range(1, n + 1):
            res = min(res, s[:k][::-1] + s[k:])
            res = min(res, s[:-k] + s[-k:][::-1])

        return res
        