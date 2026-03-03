/*
 Problem: 498. Diagonal Traverse
 Language: cpp
 Runtime: 20 ms (28.10%)
 Memory: 25.9 MB (32.35%)
 Tags: Array, Matrix, Simulation
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> arr;

        for (int d = 0; d < n + m - 1; d++) {
            vector<int> diagonal;
            int r = (d < m) ? 0 : d - m + 1;
            int c = (d < m) ? d : m - 1;

            while (r < n && c >= 0) {
                diagonal.push_back(mat[r][c]);
                r++; c--;
            }

            if (d % 2 == 0) reverse(diagonal.begin(), diagonal.end());
            arr.insert(arr.end(), diagonal.begin(), diagonal.end());
        }
        return arr;
    }
};
