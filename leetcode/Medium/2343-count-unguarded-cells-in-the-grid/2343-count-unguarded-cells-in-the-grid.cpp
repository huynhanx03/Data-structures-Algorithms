/*
 Problem: 2343. Count Unguarded Cells in the Grid
 Language: cpp
 Runtime: 75 ms (40.40%)
 Memory: 167.7 MB (85.94%)
 Tags: Array, Matrix, Simulation
*/
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> g(m, vector<char>(n));
        for (auto &x: guards) g[x[0]][x[1]] = 1;
        for (auto &x: walls) g[x[0]][x[1]] = 2;
        for (int i = 0; i < m; ++i) {
            bool seen = false;
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == 2) seen = false;
                else if (g[i][j] == 1) seen = true;
                else if (seen) g[i][j] = 3;
            }
            seen = false;
            for (int j = n - 1; j >= 0; --j) {
                if (g[i][j] == 2) seen = false;
                else if (g[i][j] == 1) seen = true;
                else if (seen) g[i][j] = 3;
            }
        }
        for (int j = 0; j < n; ++j) {
            bool seen = false;
            for (int i = 0; i < m; ++i) {
                if (g[i][j] == 2) seen = false;
                else if (g[i][j] == 1) seen = true;
                else if (seen) g[i][j] = 3;
            }
            seen = false;
            for (int i = m - 1; i >= 0; --i) {
                if (g[i][j] == 2) seen = false;
                else if (g[i][j] == 1) seen = true;
                else if (seen) g[i][j] = 3;
            }
        }
        int res = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                res += g[i][j] == 0;
        return res;
    }
};