/*
 Problem: 1817. Calculate Money in Leetcode Bank
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 7.9 MB (49.59%)
 Tags: Math
*/
class Solution {
public:
    int totalMoney(int n) {
         int w = n / 7, d = n % 7;
        return 7 * w * (w - 1) / 2 + 28 * w + w * d + d * (d + 1) / 2;
    }
};