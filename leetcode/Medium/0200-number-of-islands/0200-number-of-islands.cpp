/*
 Problem: 200. Number of Islands
 Language: cpp
 Runtime: 27 ms (56.26%)
 Memory: 16.7 MB (58.33%)
 Tags: Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> check(n, vector<bool>(m, false));
        
        int cnt = 0;
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (check[i][j] || grid[i][j] == '0') continue;

                dfs(i, j, n, m, check, grid);

                ++cnt;
            }

        return cnt;
    }

private:
    int dd[5] = {0, 1, 0, -1, 0};

    void dfs(int x, int y, const int& n, const int& m, vector<vector<bool>>& check, const vector<vector<char>>& grid) {
        for (int i = 0; i < 4; ++i) {
            int nx = x + dd[i];
            int ny = y + dd[i + 1];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || check[nx][ny] || grid[nx][ny] == '0') continue;

            check[nx][ny] = true;

            dfs(nx, ny, n, m, check, grid);
        }
    }
};