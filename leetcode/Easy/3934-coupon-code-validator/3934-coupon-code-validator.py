"""
 Problem: 3934. Coupon Code Validator
 Language: python3
 Runtime: 2 ms (95.72%)
 Memory: 18.2 MB (82.62%)
 Tags: Array, Hash Table, String, Sorting
"""
from typing import List
import re

class Solution:
    def validateCoupons(
        self,
        code: List[str],
        businessLine: List[str],
        isActive: List[bool]
    ) -> List[str]:

        order = ["electronics", "grocery", "pharmacy", "restaurant"]
        order_idx = {v: i for i, v in enumerate(order)}
        valid_bl = set(order)
        pattern = re.compile(r'^[A-Za-z0-9_]+$')

        valid = []

        for c, b, a in zip(code, businessLine, isActive):
            if (
                a
                and b in valid_bl
                and c
                and pattern.match(c)
            ):
                valid.append((order_idx[b], c))

        valid.sort()
        return [c for _, c in valid]
