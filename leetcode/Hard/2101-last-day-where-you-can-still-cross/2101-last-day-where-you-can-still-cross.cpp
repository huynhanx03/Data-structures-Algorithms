/*
 Problem: 2101. Last Day Where You Can Still Cross
 Language: cpp
 Runtime: 412 ms (21.45%)
 Memory: 262.3 MB (21.07%)
 Tags: Array, Binary Search, Depth-First Search, Breadth-First Search, Union-Find, Matrix
*/
class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1, right = row * col, ans = 0;
        vector<int> dir = {0, 1, 0, -1, 0};

        auto canCross = [&](int day) {
            vector<vector<int>> grid(row, vector<int>(col, 0));
            for (int i = 0; i < day; ++i) {
                grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
            }

            queue<pair<int,int>> q;
            vector<vector<bool>> vis(row, vector<bool>(col, false));

            for (int j = 0; j < col; ++j) {
                if (grid[0][j] == 0) {
                    q.push({0, j});
                    vis[0][j] = true;
                }
            }

            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                if (x == row - 1) return true;

                for (int k = 0; k < 4; ++k) {
                    int nx = x + dir[k];
                    int ny = y + dir[k + 1];
                    if (nx >= 0 && nx < row && ny >= 0 && ny < col &&
                        !vis[nx][ny] && grid[nx][ny] == 0) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            return false;
        };

        while (left <= right) {
            int mid = (left + right) / 2;
            if (canCross(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
