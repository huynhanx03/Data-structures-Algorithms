/*
 Problem: 733. Flood Fill
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 18.3 MB (31.57%)
 Tags: Array, Depth-First Search, Breadth-First Search, Matrix
*/
class Solution {
private:
    int dd[5] = {0, 1, 0, -1, 0};

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old = image[sr][sc];

        if (color == old) return image;

        int n = image.size();
        int m = image[0].size();

        queue<pair<int, int>> qu;
        qu.push({sr, sc});
        while (!qu.empty()) {
            auto [x, y] = qu.front();
            qu.pop();

            image[x][y] = color;

            for (int i = 0; i < 4; ++i) {
                int nx = x + dd[i];
                int ny = y + dd[i + 1];

                if (nx >= n || ny >= m || nx < 0 || ny < 0 || image[nx][ny] != old) continue;

                qu.push({nx, ny});
            }
        }

        return image;
    }
};