"""
 Problem: 28. Find the Index of the First Occurrence in a String
 Language: python3
 Runtime: 36 ms (5.07%)
 Memory: 16.6 MB (99.99%)
 Tags: Two Pointers, String, String Matching
"""
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)