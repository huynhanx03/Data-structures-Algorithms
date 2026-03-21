/*
 Problem: 3973. Flip Square Submatrix Vertically
 Language: cpp
 Runtime: 4 ms (17.77%)
 Memory: 33.8 MB (60.84%)
 Tags: Array, Two Pointers, Matrix
*/
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = 0; i < k / 2; ++i) {
            for (int j = 0; j < k; ++j) {
                swap(grid[x + i][y + j], grid[x + k - 1 - i][y + j]);
            }
        }
        return grid;
    }
};