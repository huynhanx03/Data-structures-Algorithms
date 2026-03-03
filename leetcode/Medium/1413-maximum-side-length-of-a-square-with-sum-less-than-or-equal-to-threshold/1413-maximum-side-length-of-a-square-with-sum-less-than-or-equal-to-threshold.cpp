/*
 Problem: 1413. Maximum Side Length of a Square with Sum Less than or Equal to Threshold
 Language: cpp
 Runtime: 8 ms (84.50%)
 Memory: 32.6 MB (89.30%)
 Tags: Array, Binary Search, Matrix, Prefix Sum
*/
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> pre(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                pre[i][j] = mat[i - 1][j - 1] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];

        int ans = 0;
        for (int k = 1; k <= min(m, n); ++k) {
            bool ok = false;
            for (int i = k; i <= m && !ok; ++i) {
                for (int j = k; j <= n; ++j) {
                    int sum = pre[i][j] - pre[i - k][j] - pre[i][j - k] + pre[i - k][j - k];
                    if (sum <= threshold) {
                        ok = true;
                        break;
                    }
                }
            }
            if (ok) ans = k;
            else break;
        }
        return ans;
    }
};
