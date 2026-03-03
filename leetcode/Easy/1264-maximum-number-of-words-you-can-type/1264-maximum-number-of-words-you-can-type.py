"""
 Problem: 1264. Maximum Number of Words You Can Type
 Language: python3
 Runtime: 0 ms (100.00%)
 Memory: 18.1 MB (91.01%)
 Tags: Hash Table, String
"""
class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        words = text.split(" ")
        res = len(words)
        arr = [False] * 26

        for c in brokenLetters:
            arr[ord(c) - ord('a')] = True

        for word in words:
            for c in word:
                if arr[ord(c) - ord('a')]:
                    res -= 1
                    break
        
        return res
