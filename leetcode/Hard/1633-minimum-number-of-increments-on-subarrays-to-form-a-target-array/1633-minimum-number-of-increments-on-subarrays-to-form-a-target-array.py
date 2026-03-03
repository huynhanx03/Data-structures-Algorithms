"""
 Problem: 1633. Minimum Number of Increments on Subarrays to Form a Target Array
 Language: python3
 Runtime: 30 ms (84.04%)
 Memory: 26.7 MB (100.00%)
 Tags: Array, Dynamic Programming, Stack, Greedy, Monotonic Stack
"""
class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        ops = target[0]
        for i in range(1, len(target)):
            if target[i] > target[i - 1]:
                ops += target[i] - target[i - 1]
        return ops