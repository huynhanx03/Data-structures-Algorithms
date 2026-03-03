/*
 Problem: 123. Best Time to Buy and Sell Stock III
 Language: cpp
 Runtime: 147 ms (54.25%)
 Memory: 139.7 MB (52.30%)
 Tags: Array, Dynamic Programming
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<vector<int>> dp(n + 1, vector<int>(5, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = 1; j <= 4; ++j) {
                if (j % 2 == 0) {
                    // Buy
                    dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - 1] - prices[i]);
                } else {
                    // Sell
                    dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - 1] + prices[i]);
                }
            }
        }

        return dp[0][4];
    }
};
