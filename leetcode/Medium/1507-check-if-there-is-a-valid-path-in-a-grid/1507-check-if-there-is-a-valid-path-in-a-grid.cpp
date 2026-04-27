/*
 Problem: 1507. Check if There is a Valid Path in a Grid
 Language: cpp
 Runtime: 20 ms (72.58%)
 Memory: 72.6 MB (18.55%)
 Tags: Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix
*/
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        int dd[5] = {-1, 0, 1, 0, -1};

        vector<vector<int>> dir = {
            {},
            {1, 3},
            {0, 2},
            {2, 3},
            {1, 2},
            {0, 3},
            {0, 1}
        };

        auto ok = [&](int d, int nx, int ny) {
            int b = (d + 2) % 4;
            for (auto x : dir[grid[nx][ny]])
                if (x == b) return true;
            return false;
        };

        auto dfs = [&](auto&& self, int x, int y) -> bool {
            if (x == n - 1 && y == m - 1) return true;
            vis[x][y] = 1;

            for (const auto& d : dir[grid[x][y]]) {
                int nx = x + dd[d], ny = y + dd[d + 1];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (vis[nx][ny]) continue;
                if (!ok(d, nx, ny)) continue;
                if (self(self, nx, ny)) return true;
            }
            return false;
        };

        return dfs(dfs, 0, 0);
    }
};