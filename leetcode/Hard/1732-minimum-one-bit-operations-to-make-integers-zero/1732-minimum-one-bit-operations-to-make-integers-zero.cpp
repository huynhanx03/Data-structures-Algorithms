/*
 Problem: 1732. Minimum One Bit Operations to Make Integers Zero
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.2 MB (21.38%)
 Tags: Math, Dynamic Programming, Bit Manipulation, Recursion, Memoization
*/
class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0;
        while (n) {
            ans ^= n;
            n >>= 1;
        }
        return ans;
    }
};
