"""
 Problem: 1666. Make The String Great
 Language: python3
 Runtime: 33 ms (6.45%)
 Memory: 16.5 MB (100.00%)
 Tags: String, Stack
"""
class Solution:
    def makeGood(self, s: str) -> str:
        stack = []  
        for char in s:
            if stack and abs(ord(char) - ord(stack[-1])) == 32:
                stack.pop()
            else:
                stack.append(char)

        return ''.join(stack)