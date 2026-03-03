"""
 Problem: 2307. Replace Non-Coprime Numbers in Array
 Language: python3
 Runtime: 123 ms (57.72%)
 Memory: 31.5 MB (96.75%)
 Tags: Array, Math, Stack, Number Theory
"""
class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        stack = []
        for num in nums:
            while stack and gcd(stack[-1], num) > 1:
                num = lcm(stack.pop(), num)
            stack.append(num)

        return stack
