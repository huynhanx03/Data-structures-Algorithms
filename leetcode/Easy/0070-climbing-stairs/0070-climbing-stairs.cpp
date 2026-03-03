/*
 Problem: 70. Climbing Stairs
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 7.8 MB (86.20%)
 Tags: Math, Dynamic Programming, Memoization
*/
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 5);
        
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n - 1];
    }
};