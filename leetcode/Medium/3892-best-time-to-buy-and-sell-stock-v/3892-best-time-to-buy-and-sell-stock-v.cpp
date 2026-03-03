/*
 Problem: 3892. Best Time to Buy and Sell Stock V
 Language: cpp
 Runtime: 39 ms (85.49%)
 Memory: 30.3 MB (86.39%)
 Tags: Array, Dynamic Programming
*/
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        const long long NEG_INF = -1e18;
        
        vector<vector<long long>> dp(k + 1, vector<long long>(3, NEG_INF));
        dp[0][0] = 0; // chưa giao dịch, không giữ gì

        for (int price : prices) {
            for (int t = k; t >= 0; --t) {
                // open positions
                dp[t][1] = max(dp[t][1], dp[t][0] - price); // buy (long)
                dp[t][2] = max(dp[t][2], dp[t][0] + price); // sell (short)

                // close positions
                if (t + 1 <= k) {
                    dp[t + 1][0] = max(dp[t + 1][0], dp[t][1] + price); // sell long
                    dp[t + 1][0] = max(dp[t + 1][0], dp[t][2] - price); // buy back short
                }
            }
        }

        long long ans = 0;
        for (int t = 0; t <= k; ++t) {
            ans = max(ans, dp[t][0]);
        }
        return ans;
    }
};
