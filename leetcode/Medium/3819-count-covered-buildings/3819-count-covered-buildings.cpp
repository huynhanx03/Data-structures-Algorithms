/*
 Problem: 3819. Count Covered Buildings
 Language: cpp
 Runtime: 16 ms (92.83%)
 Memory: 283.8 MB (86.76%)
 Tags: Array, Hash Table, Sorting
*/
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> row_min(n, n), row_max(n, -1);
        vector<int> col_min(n, n), col_max(n, -1);
        for (auto &b : buildings) {
            int x = b[0] - 1;
            int y = b[1] - 1;
            if (y < row_min[x]) row_min[x] = y;
            if (y > row_max[x]) row_max[x] = y;
            if (x < col_min[y]) col_min[y] = x;
            if (x > col_max[y]) col_max[y] = x;
        }
        int ans = 0;
        for (auto &b : buildings) {
            int x = b[0] - 1;
            int y = b[1] - 1;
            if (row_min[x] < y && y < row_max[x] &&
                col_min[y] < x && x < col_max[y])
                ++ans;
        }
        return ans;
    }
};
