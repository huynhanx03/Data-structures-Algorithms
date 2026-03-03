/*
 Problem: 1064. Smallest Integer Divisible by K
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 7.9 MB (52.35%)
 Tags: Hash Table, Math
*/
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0)
            return -1;

        int remainder = 0;
        for (int len = 1; len <= k; ++len) {
            remainder = (remainder * 10 + 1) % k;
            if (remainder == 0)
                return len;
        }
        return -1;
    }
};