"""
 Problem: 7. Reverse Integer
 Language: python3
 Runtime: 30 ms (98.87%)
 Memory: 18 MB (92.75%)
 Tags: Math
"""
class Solution:
    def reverse(self, x: int) -> int:
        INT_MIN, INT_MAX = -2**31, 2**31 - 1
        sign = -1 if x < 0 else 1
        rev = int(str(abs(x))[::-1]) * sign
        return rev if INT_MIN <= rev <= INT_MAX else 0
        