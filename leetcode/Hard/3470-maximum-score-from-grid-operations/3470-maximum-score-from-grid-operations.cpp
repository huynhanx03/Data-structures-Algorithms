/*
 Problem: 3470. Maximum Score From Grid Operations
 Language: cpp
 Runtime: 631 ms (20.88%)
 Memory: 637.5 MB (5.09%)
 Tags: Array, Dynamic Programming, Matrix, Prefix Sum
*/
class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) return 0;

        vector<vector<long long>> prefix(n, vector<long long>(n + 1));

        for (int j = 0; j < n; ++j)
            for (int i = 0; i < n; ++i)
                prefix[j][i + 1] = prefix[j][i] + grid[i][j];

        int m = n + 1;
        long long neg = -4e18;

        vector<vector<long long>> dp(m, vector<long long>(m, neg));

        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                dp[i][j] = j > i ? prefix[0][j] - prefix[0][i] : 0;

        for (int col = 1; col < n - 1; ++col) {
            vector<vector<long long>> newDp(m, vector<long long>(m, neg));

            for (int j = 0; j <= n; ++j) {
                vector<long long> pref(m, neg), mid(m + 1, neg), suf(m + 1, neg);

                pref[0] = dp[0][j];
                for (int i = 1; i <= n; ++i)
                    pref[i] = max(pref[i - 1], dp[i][j]);

                for (int i = j; i >= 0; --i)
                    mid[i] = max(mid[i + 1], dp[i][j]);

                for (int i = n; i >= 0; --i)
                    suf[i] = max(suf[i + 1], dp[i][j] + prefix[col][i]);

                for (int k = 0; k <= n; ++k) {
                    long long best = pref[k];

                    if (k > j)
                        best += prefix[col][k] - prefix[col][j];

                    if (k < j)
                        best = max(best, mid[k + 1]);

                    int start = max(j, k) + 1;
                    if (start <= n)
                        best = max(best, suf[start] - prefix[col][j]);

                    newDp[j][k] = best;
                }
            }

            dp = newDp;
        }

        long long ans = 0;

        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                ans = max(ans, dp[i][j] + (i > j ? prefix[n - 1][i] - prefix[n - 1][j] : 0));

        return ans;
    }
};