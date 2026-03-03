/*
 Problem: 279. Perfect Squares
 Language: cpp
 Runtime: 44 ms (62.46%)
 Memory: 13 MB (82.43%)
 Tags: Math, Dynamic Programming, Breadth-First Search
*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};