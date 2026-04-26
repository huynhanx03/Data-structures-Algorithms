/*
 Problem: 1663. Detect Cycles in 2D Grid
 Language: cpp
 Runtime: 23 ms (78.23%)
 Memory: 73.1 MB (44.32%)
 Tags: Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix
*/
class Solution {
public:
    int n, m;
    vector<vector<int>> vis;
    vector<vector<char>> g;
    int dd[5] = {0, 1, 0, -1, 0};

    bool dfs(int x, int y, int px, int py) {
        vis[x][y] = 1;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dd[d];
            int ny = y + dd[d + 1];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (g[nx][ny] != g[x][y]) continue;
            if (nx == px && ny == py) continue;

            if (vis[nx][ny]) return true;

            if (dfs(nx, ny, x, y)) return true;
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        g = grid;
        n = g.size();
        m = g[0].size();

        vis.assign(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!vis[i][j]) {
                    if (dfs(i, j, -1, -1)) return true;
                }
            }
        }

        return false;
    }
};