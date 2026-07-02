/*
 Problem: 2043. Cyclically Rotating a Grid
 Language: cpp
 Runtime: 19 ms (27.73%)
 Memory: 18.3 MB (21.09%)
 Tags: Array, Matrix, Simulation
*/
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int l = 0; l < layers; ++l) {
            int top = l;
            int left = l;
            int bottom = m - 1 - l;
            int right = n - 1 - l;

            vector<int> vals;

            for (int i = top; i <= bottom; ++i) {
                vals.push_back(grid[i][left]);
            }

            for (int j = left + 1; j <= right; ++j) {
                vals.push_back(grid[bottom][j]);
            }

            for (int i = bottom - 1; i >= top; --i) {
                vals.push_back(grid[i][right]);
            }

            for (int j = right - 1; j > left; --j) {
                vals.push_back(grid[top][j]);
            }

            int len = vals.size();
            int shift = k % len;

            vector<int> rotated(len);

            for (int i = 0; i < len; ++i) {
                rotated[(i + shift) % len] = vals[i];
            }

            int idx = 0;

            for (int i = top; i <= bottom; ++i) {
                grid[i][left] = rotated[idx++];
            }

            for (int j = left + 1; j <= right; ++j) {
                grid[bottom][j] = rotated[idx++];
            }

            for (int i = bottom - 1; i >= top; --i) {
                grid[i][right] = rotated[idx++];
            }

            for (int j = right - 1; j > left; --j) {
                grid[top][j] = rotated[idx++];
            }
        }

        return grid;
    }
};