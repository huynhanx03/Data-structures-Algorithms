/*
 Problem: 1402. Count Square Submatrices with All Ones
 Language: cpp
 Runtime: 6 ms (60.80%)
 Memory: 27.6 MB (86.31%)
 Tags: Array, Dynamic Programming, Matrix
*/
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0;

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] && i > 0 && j > 0) {
                    matrix[i][j] = min({matrix[i - 1][j], 
                        matrix[i][j - 1], matrix[i - 1][j - 1]}) + 1;
                }

                res += matrix[i][j];
            }
        }

        return res;
    }
};