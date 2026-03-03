"""
 Problem: 151. Reverse Words in a String
 Language: python
 Runtime: 14 ms (6.51%)
 Memory: 12 MB (99.98%)
 Tags: Two Pointers, String
"""
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        x = s.split()
        d = x[::-1]
        ans = " ".join(d)
        return ans