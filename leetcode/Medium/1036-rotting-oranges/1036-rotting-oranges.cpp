/*
 Problem: 1036. Rotting Oranges
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 17.2 MB (30.83%)
 Tags: Array, Breadth-First Search, Matrix
*/
class Solution {
private:
    int dd[5] = {0, 1, 0, -1, 0};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> check(n, vector<bool>(m, false));

        queue<pair<int, pair<int, int>>> qu;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == 2) {
                    qu.push({0, {i, j}});
                    check[i][j] = true;
                }

        int ans = 0;

        while (!qu.empty()) {
            auto [cnt, pos] = qu.front();
            auto [x, y] = pos;
            
            ans = max(ans, cnt);

            qu.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = x + dd[i];
                int ny = y + dd[i + 1];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m || check[nx][ny] || grid[nx][ny] != 1) continue;

                qu.push({cnt + 1, {nx, ny}});

                check[nx][ny] = true;
            }
        }

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == 1 && !check[i][j]) {
                    return -1;
                }

        return ans;
    }
};
