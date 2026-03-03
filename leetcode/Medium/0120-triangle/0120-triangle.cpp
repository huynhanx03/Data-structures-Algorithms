/*
 Problem: 120. Triangle
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 13.4 MB (41.19%)
 Tags: Array, Dynamic Programming
*/
class Solution {
public:
    const int oo = 1e9;

    int minimumTotal(vector<vector<int>>& triangle) {
        // dp:
        // - index
        // - i

        int n = triangle.size();

        vector<vector<int>> dp(n + 5, vector<int>(n + 5, oo));

        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                for (int j = 0; j < triangle[i].size(); ++j) {
                    dp[i][j] = triangle[i][j];
                }
            } else {
                for (int j = 0; j < triangle[i].size(); ++j) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + triangle[i][j]);

                    if (j > 0) {
                        dp[i][j] =
                            min(dp[i][j], dp[i - 1][j - 1] + triangle[i][j]);
                    }
                }
            }
        }

        int ans = oo;

        for (int i = 0; i < triangle[n - 1].size(); ++i) {
            ans = min(ans, dp[n - 1][i]);
        }

        return ans;
    }
};