/*
 Problem: 1569. Max Dot Product of Two Subsequences
 Language: cpp
 Runtime: 19 ms (51.08%)
 Memory: 17.9 MB (45.75%)
 Tags: Array, Dynamic Programming
*/
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        const int NEG_INF = -1e9;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, NEG_INF));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int prod = nums1[i-1] * nums2[j-1];

                dp[i][j] = max({
                    prod,
                    dp[i-1][j-1] + prod,
                    dp[i-1][j],
                    dp[i][j-1]
                });
            }
        }

        return dp[n][m];
    }
};