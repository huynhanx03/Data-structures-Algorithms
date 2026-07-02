/*
 Problem: 48. Rotate Image
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 10.3 MB (34.78%)
 Tags: Array, Math, Matrix
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};