/*
 Problem: 188. Best Time to Buy and Sell Stock IV
 Language: cpp
 Runtime: 4 ms (71.06%)
 Memory: 17.6 MB (59.63%)
 Tags: Array, Dynamic Programming
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<vector<int>> dp(n + 1, vector<int>(k * 2 + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = 1; j <= k * 2; ++j) {
                if (j % 2 == 0) {
                    // Buy
                    dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - 1] - prices[i]);
                } else {
                    // Sell
                    dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - 1] + prices[i]);
                }
            }
        }

        return dp[0][k * 2];
    }
};