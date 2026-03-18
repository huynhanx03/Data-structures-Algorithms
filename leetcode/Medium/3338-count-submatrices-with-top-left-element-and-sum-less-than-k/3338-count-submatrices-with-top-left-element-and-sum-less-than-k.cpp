/*
 Problem: 3338. Count Submatrices with Top-Left Element and Sum Less Than k
 Language: cpp
 Runtime: 20 ms (33.15%)
 Memory: 110.3 MB (8.99%)
 Tags: Array, Matrix, Prefix Sum
*/
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        vector<vector<long long>> pre(m + 1, vector<long long>(n + 1, 0));
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                pre[i][j] = grid[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
                if (pre[i][j] <= k) ++res;
                else break;
            }
        }

        return res;
    }
};