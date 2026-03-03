/*
 Problem: 3676. Smallest Number With All Set Bits
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.1 MB (99.45%)
 Tags: Math, Bit Manipulation
*/
class Solution {
public:
    int smallestNumber(int n) {
        int mask = 1;
        while (mask <= n) mask <<= 1;
        return mask - 1;
    }
};