"""
 Problem: 1448. Maximum 69 Number
 Language: python3
 Runtime: 0 ms (100.00%)
 Memory: 18 MB (88.74%)
 Tags: Math, Greedy
"""
class Solution:
    def maximum69Number (self, num: int) -> int:
        return int(str(num).replace('6', '9', 1))