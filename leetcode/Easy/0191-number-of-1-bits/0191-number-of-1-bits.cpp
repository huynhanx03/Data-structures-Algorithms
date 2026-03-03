/*
 Problem: 191. Number of 1 Bits
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.2 MB (48.24%)
 Tags: Divide and Conquer, Bit Manipulation
*/
class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;

        while (n != 0) {
            cnt += n & 1;
            n >>= 1;
        }

        return cnt;
    }
};