"""
 Problem: 290. Word Pattern
 Language: python3
 Runtime: 40 ms (0.06%)
 Memory: 16.6 MB (100.00%)
 Tags: Hash Table, String
"""
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        mapping = {}
        s = s.split()
        if len(pattern) != len(s):
            return False

        for char, word in zip(pattern, s):
            if char in mapping:
                if mapping[char] != word:
                    return False
            else:
                mapping[char] = word

        return len(set(mapping.keys())) == len(set(mapping.values()))