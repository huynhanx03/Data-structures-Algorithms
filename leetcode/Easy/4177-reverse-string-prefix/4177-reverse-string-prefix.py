"""
 Problem: 4177. Reverse String Prefix
 Language: python3
 Runtime: 4 ms (4.00%)
 Memory: 17.5 MB (48.21%)
 Tags: Two Pointers, String
"""
class Solution(object):
    def reversePrefix(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        return s[:k][::-1] + s[k:]
        