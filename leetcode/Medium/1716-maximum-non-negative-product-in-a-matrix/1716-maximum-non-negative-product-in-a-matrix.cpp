/*
 Problem: 1716. Maximum Non Negative Product in a Matrix
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 14.1 MB (74.44%)
 Tags: Array, Dynamic Programming, Matrix
*/
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        const long long MOD = 1e9 + 7;

        vector<vector<long long>> maxDp(n, vector<long long>(m));
        vector<vector<long long>> minDp(n, vector<long long>(m));

        maxDp[0][0] = grid[0][0];
        minDp[0][0] = grid[0][0];

        for (int j = 1; j < m; ++j) {
            maxDp[0][j] = maxDp[0][j - 1] * grid[0][j];
            minDp[0][j] = maxDp[0][j];
        }

        for (int i = 1; i < n; ++i) {
            maxDp[i][0] = maxDp[i - 1][0] * grid[i][0];
            minDp[i][0] = maxDp[i][0];
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                maxDp[i][j] = max({
                    maxDp[i - 1][j] * grid[i][j],
                    maxDp[i][j - 1] * grid[i][j],
                    minDp[i - 1][j] * grid[i][j],
                    minDp[i][j - 1] * grid[i][j]
                });

                minDp[i][j] = min({
                    maxDp[i - 1][j] * grid[i][j],
                    maxDp[i][j - 1] * grid[i][j],
                    minDp[i - 1][j] * grid[i][j],
                    minDp[i][j - 1] * grid[i][j]
                });
            }
        }

        return maxDp[n - 1][m - 1] < 0 ? -1 : maxDp[n - 1][m - 1] % MOD;
    }
};