"""
 Problem: 165. Compare Version Numbers
 Language: python3
 Runtime: 0 ms (100.00%)
 Memory: 17.7 MB (93.37%)
 Tags: Two Pointers, String
"""
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = version1.split(".")
        v2 = version2.split(".")

        max_len = max(len(v1), len(v2))
        v1 += ["0"] * (max_len - len(v1))
        v2 += ["0"] * (max_len - len(v2))

        for i in range(max_len):
            n1, n2 = int(v1[i]), int(v2[i])
            if n1 < n2:
                return -1
            elif n1 > n2:
                return 1

        return 0
