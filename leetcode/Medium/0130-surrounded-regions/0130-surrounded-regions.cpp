/*
 Problem: 130. Surrounded Regions
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 14.9 MB (28.16%)
 Tags: Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix
*/
class Solution {
private:
    int dd[5] = {0, 1, 0, -1, 0};

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> check(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) &&
                    board[i][j] == 'O') {
                    check[i][j] = true;
                    q.push({i, j});
                }
            }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = x + dd[i];
                int ny = y + dd[i + 1];

                if (nx >= n || ny >= m || nx < 0 || ny < 0 || check[nx][ny] ||
                    board[nx][ny] == 'X')
                    continue;

                q.push({nx, ny});
                check[nx][ny] = true;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                if (!check[i][j])
                    board[i][j] = 'X';
        }
    }
};