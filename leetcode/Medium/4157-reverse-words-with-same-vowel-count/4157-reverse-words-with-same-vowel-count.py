"""
 Problem: 4157. Reverse Words With Same Vowel Count
 Language: python3
 Runtime: 207 ms (53.34%)
 Memory: 23.9 MB (28.34%)
 Tags: Two Pointers, String, Simulation
"""
class Solution:
    def reverseWords(self, s: str) -> str:
        vowels = "aeiou"

        words = s.split()

        if not words:
            return ""

        f = sum(1 for c in words[0] if c in vowels)

        res = [words[0]]
        
        for word in words[1:]:
            if sum(1 for c in word if c in vowels) == f:
                res.append(word[::-1])
            else:
                res.append(word)

        return " ".join(res)