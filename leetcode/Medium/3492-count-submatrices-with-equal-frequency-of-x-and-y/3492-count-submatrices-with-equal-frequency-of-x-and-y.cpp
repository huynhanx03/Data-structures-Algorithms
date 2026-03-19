/*
 Problem: 3492. Count Submatrices With Equal Frequency of X and Y
 Language: cpp
 Runtime: 71 ms (35.77%)
 Memory: 130.2 MB (50.41%)
 Tags: Array, Matrix, Prefix Sum
*/
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> sum(m, vector<int>(n)), cntX(m, vector<int>(n));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int v = (grid[i][j] == 'X') ? 1 : (grid[i][j] == 'Y' ? -1 : 0);
                int x = (grid[i][j] == 'X');

                sum[i][j] = v;
                cntX[i][j] = x;

                if (i) {
                    sum[i][j] += sum[i-1][j];
                    cntX[i][j] += cntX[i-1][j];
                }
                if (j) {
                    sum[i][j] += sum[i][j-1];
                    cntX[i][j] += cntX[i][j-1];
                }
                if (i && j) {
                    sum[i][j] -= sum[i-1][j-1];
                    cntX[i][j] -= cntX[i-1][j-1];
                }

                if (sum[i][j] == 0 && cntX[i][j] > 0) ++ans;
            }
        }
        return ans;
    }
};