/*
 Problem: 3215. Matrix Similarity After Cyclic Shifts
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 31.3 MB (49.69%)
 Tags: Array, Math, Matrix, Simulation
*/
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        k %= m;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int nj = (i % 2 == 0)
                    ? (j + k) % m
                    : (j - k + m) % m;

                if (mat[i][j] != mat[i][nj]) return false;
            }
        }
        return true;
    }
};