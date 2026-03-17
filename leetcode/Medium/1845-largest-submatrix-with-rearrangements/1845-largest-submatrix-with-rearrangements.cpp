/*
 Problem: 1845. Largest Submatrix With Rearrangements
 Language: cpp
 Runtime: 28 ms (75.00%)
 Memory: 90.1 MB (46.28%)
 Tags: Array, Greedy, Sorting, Matrix
*/
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> h(n, 0);
        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                h[j] = matrix[i][j] ? h[j] + 1 : 0;

            vector<int> row = h;
            sort(row.begin(), row.end(), greater<int>());

            for (int j = 0; j < n; j++)
                res = max(res, row[j] * (j + 1));
        }

        return res;
    }
};