/*
 Problem: 338. Counting Bits
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 10.6 MB (80.40%)
 Tags: Dynamic Programming, Bit Manipulation
*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; ++i)
            dp[i] = dp[i >> 1] + (i & 1);
        
        return dp;
    }
};
