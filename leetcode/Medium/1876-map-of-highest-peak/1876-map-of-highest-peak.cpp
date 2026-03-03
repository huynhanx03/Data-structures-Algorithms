/*
 Problem: 1876. Map of Highest Peak
 Language: cpp
 Runtime: 76 ms (62.33%)
 Memory: 112.8 MB (85.63%)
 Tags: Array, Breadth-First Search, Matrix
*/
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        
        queue<pair<int, int>> qu;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (isWater[i][j] == 1) {
                    qu.push({i, j});
                    isWater[i][j] = -1;
                }

        int cnt = 0;

        vector<vector<int>> ans(n, vector<int>(m, 0));

        while (!qu.empty()) {
            int sz = qu.size();

            for (int i = 0; i < sz; ++i) {
                const auto [x, y] = qu.front();
                qu.pop();

                ans[x][y] = cnt;

                for (int j = 0; j < 4; ++j) {
                    int nx = x + dd[j];
                    int ny = y + dd[j + 1];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || isWater[nx][ny] == -1)
                        continue;

                    isWater[nx][ny] = -1;
                    qu.push({nx, ny});
                }
            }

            ++cnt;
        }

        return ans;
    }

private:
    int dd[5] = {0, 1, 0, -1, 0};
};