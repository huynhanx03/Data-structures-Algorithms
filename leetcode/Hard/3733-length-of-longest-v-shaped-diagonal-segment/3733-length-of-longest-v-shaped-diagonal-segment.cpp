/*
 Problem: 3733. Length of Longest V-Shaped Diagonal Segment
 Language: cpp
 Runtime: 502 ms (45.22%)
 Memory: 298.3 MB (16.24%)
 Tags: Array, Dynamic Programming, Memoization, Matrix
*/
class Solution {
private:
    int dx[4] = {1, 1, -1, -1};
    int dy[4] = {1, -1, -1, 1};

public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(1 << 3, 0)));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 1)
                    continue;

                vector<int> maxs = {n - i, j + 1, i + 1, m - j};
                
                for (int k = 0; k < 4; k++) {
                    if (maxs[k] > ans) {
                        ans = max(ans, dfs(i, j, n, m, k, 1, 2, grid, dp) + 1);
                    }
                }
            }
        }

        return ans;
    }

    int dfs(int i, int j, int n, int m, int k, bool canTurn, int target,
            vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        i += dx[k];
        j += dy[k];

        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != target) {
            return 0;
        }

        int mask = (k << 1) | canTurn;
        if (dp[i][j][mask] > 0)
            return dp[i][j][mask];

        int res = dfs(i, j, n, m, k, canTurn, 2 - target, grid, dp);
        
        if (canTurn == 1) {
            vector<int> maxs = {n - i - 1, j, i, m - j - 1};
            int nk = (k + 1) % 4;
            if (maxs[nk] > res) {
                res = max(res, dfs(i, j, n, m, nk, 0, 2 - target, grid, dp));
            }
        }

        return dp[i][j][mask] = res + 1;
    }
};