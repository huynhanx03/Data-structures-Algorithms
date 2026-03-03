/*
 Problem: 870. Magic Squares In Grid
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 11.7 MB (50.86%)
 Tags: Array, Hash Table, Math, Matrix
*/
class Solution {
public:
    bool isMagic(vector<vector<int>>& g, int n, int m) {
        if (g[n+1][m+1] != 5) return false;

        int cnt[10] = {};
        for (int i = n; i < n + 3; ++i) {
            for (int j = m; j < m + 3; ++j) {
                int v = g[i][j];
                if (v < 1 || v > 9 || cnt[v]++) return false;
            }
        }

        for (int i = 0; i < 3; ++i) {
            if (g[n+i][m] + g[n+i][m+1] + g[n+i][m+2] != 15) return false;
            if (g[n][m+i] + g[n+1][m+i] + g[n+2][m+i] != 15) return false;
        }

        if (g[n][m] + g[n+1][m+1] + g[n+2][m+2] != 15) return false;
        if (g[n][m+2] + g[n+1][m+1] + g[n+2][m] != 15) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;

        for (int i = 0; i + 2 < n; ++i) {
            for (int j = 0; j + 2 < m; ++j) {
                if (isMagic(grid, i, j)) ++ans;
            }
        }
        return ans;
    }
};
