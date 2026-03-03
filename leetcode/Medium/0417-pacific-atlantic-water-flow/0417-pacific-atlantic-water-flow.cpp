/*
 Problem: 417. Pacific Atlantic Water Flow
 Language: cpp
 Runtime: 3 ms (87.55%)
 Memory: 24 MB (34.05%)
 Tags: Array, Depth-First Search, Breadth-First Search, Matrix
*/
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        vector<vector<int>> res;
        vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        function<void(int, int, vector<vector<bool>>&)> dfs =
            [&](int r, int c, vector<vector<bool>>& ocean) {
                if (ocean[r][c])
                    return;
                ocean[r][c] = true;
                for (auto [dr, dc] : dirs) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        heights[nr][nc] >= heights[r][c])
                        dfs(nr, nc, ocean);
                }
            };

        for (int i = 0; i < m; i++) {
            dfs(i, 0, pac);     // Pacific left
            dfs(i, n - 1, atl); // Atlantic right
        }
        for (int j = 0; j < n; j++) {
            dfs(0, j, pac);     // Pacific top
            dfs(m - 1, j, atl); // Atlantic bottom
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pac[i][j] && atl[i][j])
                    res.push_back({i, j});
        return res;
    }
};