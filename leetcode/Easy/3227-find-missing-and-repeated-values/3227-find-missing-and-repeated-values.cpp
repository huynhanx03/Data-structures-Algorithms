/*
 Problem: 3227. Find Missing and Repeated Values
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 26.9 MB (58.73%)
 Tags: Array, Hash Table, Math, Matrix
*/
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n * n;
        vector<int> count(total + 1, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                count[grid[i][j]]++;
            }
        }

        int repeated = -1, missing = -1;

        for (int i = 1; i <= total; ++i) {
            if (count[i] == 2) {
                repeated = i;
            } else if (count[i] == 0) {
                missing = i;
            }
        }

        return {repeated, missing};
    }
};