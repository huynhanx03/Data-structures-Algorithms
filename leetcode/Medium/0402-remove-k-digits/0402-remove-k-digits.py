"""
 Problem: 402. Remove K Digits
 Language: python
 Runtime: 53 ms (32.80%)
 Memory: 13.2 MB (99.52%)
 Tags: String, Stack, Greedy, Monotonic Stack
"""
class Solution(object):
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        stack = []
        
        for digit in num:
            while stack and k > 0 and stack[-1] > digit:
                stack.pop()
                k -= 1
            stack.append(digit)
        
        stack = stack[:-k] if k > 0 else stack
        
        result = ''.join(stack).lstrip('0')
        
        return result if result else '0'                
        