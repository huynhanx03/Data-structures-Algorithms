/*
 Problem: 62. Unique Paths
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 9.3 MB (51.76%)
 Tags: Math, Dynamic Programming, Combinatorics
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector <vector<long long>> dp(n, vector<long long>(m, 0));

        dp[0][0] = 1;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (i > 0)
                    dp[i][j] += dp[i - 1][j];
                
                if (j > 0)
                    dp[i][j] += dp[i][j - 1];
            }

        return dp[n - 1][m - 1];
    }
};