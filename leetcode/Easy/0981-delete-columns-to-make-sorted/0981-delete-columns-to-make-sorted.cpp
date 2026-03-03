/*
 Problem: 981. Delete Columns to Make Sorted
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 15.3 MB (96.84%)
 Tags: Array, String
*/
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int deleted = 0;

        for (int col = 0; col < m; ++col) {
            for (int row = 1; row < n; ++row) {
                if (strs[row][col] < strs[row - 1][col]) {
                    ++deleted;
                    break;
                }
            }
        }
        return deleted;
    }
};
