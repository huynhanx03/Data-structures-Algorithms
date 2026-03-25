/*
 Problem: 3849. Equal Sum Grid Partition I
 Language: cpp
 Runtime: 21 ms (27.34%)
 Memory: 128.5 MB (68.71%)
 Tags: Array, Matrix, Enumeration, Prefix Sum
*/
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        long long total = 0;
        for (const auto& row : grid) {
            for (const auto& val : row) {
                total += val;
            }
        }

        if (total % 2 != 0) return false;

        long long half = total / 2;

        long long sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < m; ++j) {
                sum += grid[i][j];
            }
            if (sum == half) return true;
        }

        vector<long long> colSum(m, 0);
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                colSum[j] += grid[i][j];
            }
        }

        sum = 0;
        for (int j = 0; j < m - 1; ++j) {
            sum += colSum[j];
            if (sum == half) return true;
        }

        return false;
    }
};