/*
 Problem: 4283. Multi Source Flood Fill
 Language: cpp
 Runtime: 126 ms (88.82%)
 Memory: 210.7 MB (82.74%)
 Tags: None
*/
class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        const int IMX = 1e9;
        
        vector<vector<int>> g(n, vector<int>(m, 0));
        vector<vector<int>> d(n, vector<int>(m, IMX));

        queue<pair<int, int>> q;
        
        for (const auto& s : sources) {
            int x = s[0];
            int y = s[1];
            int v = s[2];

            if (d[x][y] > 0) {
                d[x][y] = 0;
                g[x][y] = v;

                q.push({x, y});
            } else {
                g[x][y] = max(g[x][y], v);
            }
        }

        int dd[5] = {0, -1, 0, 1, 0};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int xx = x + dd[i];
                int yy = y + dd[i + 1];

                if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;

                int nd = d[x][y] + 1;
                if (d[xx][yy] > nd) {
                    d[xx][yy] = nd;
                    g[xx][yy] = g[x][y];
                    q.push({xx, yy});
                } else if (d[xx][yy] == nd && g[xx][yy] < g[x][y]) {
                    g[xx][yy] = g[x][y];
                    q.push({xx, yy});
                }
            }
        }

        return g;
    }
};