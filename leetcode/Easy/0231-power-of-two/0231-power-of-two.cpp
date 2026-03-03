/*
 Problem: 231. Power of Two
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 7.7 MB (81.19%)
 Tags: Math, Bit Manipulation, Recursion
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};