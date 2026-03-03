"""
 Problem: 3768. Check If Digits Are Equal in String After Operations I
 Language: python3
 Runtime: 95 ms (5.30%)
 Memory: 17.8 MB (88.84%)
 Tags: Math, String, Simulation, Combinatorics, Number Theory
"""
class Solution:
    def hasSameDigits(self, s: str) -> bool:
        while len(s) > 2:
            new_s = ''
            for i in range(len(s) - 1):
                new_digit = (int(s[i]) + int(s[i + 1])) % 10
                new_s += str(new_digit)
            s = new_s
        return s[0] == s[1]