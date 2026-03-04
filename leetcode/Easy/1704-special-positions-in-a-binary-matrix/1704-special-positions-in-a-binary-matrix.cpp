/*
 Problem: 1704. Special Positions in a Binary Matrix
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 17.1 MB (20.57%)
 Tags: Array, Matrix
*/
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> row(m, 0), col(n, 0);
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                row[i] += mat[i][j];
                col[j] += mat[i][j];
            }

        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (mat[i][j] && row[i] == 1 && col[j] == 1)
                    ++ans;

        return ans;
    }
};