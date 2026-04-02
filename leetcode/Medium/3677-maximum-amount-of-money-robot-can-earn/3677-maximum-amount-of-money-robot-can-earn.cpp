/*
 Problem: 3677. Maximum Amount of Money Robot Can Earn
 Language: cpp
 Runtime: 579 ms (45.53%)
 Memory: 276 MB (37.87%)
 Tags: Array, Dynamic Programming, Matrix
*/
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        const int INF = -1e9;

        vector dp(m, vector(n, vector<int>(3, INF)));

        dp[0][0][0] = coins[0][0];
        if (coins[0][0] < 0) dp[0][0][1] = 0;

        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                if (i == 0 && j == 0) continue;

                int val = coins[i][j];

                for (int k = 0; k < 3; ++k) {
                    if (i > 0) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k] + val);
                        if (val < 0 && k > 0)
                            dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1]);
                    }
                    if (j > 0) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k] + val);
                        if (val < 0 && k > 0)
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1]);
                    }
                }
            }
        }

        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};