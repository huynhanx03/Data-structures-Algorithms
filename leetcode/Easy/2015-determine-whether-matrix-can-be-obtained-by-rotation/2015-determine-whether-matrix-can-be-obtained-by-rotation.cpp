/*
 Problem: 2015. Determine Whether Matrix Can Be Obtained By Rotation
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 14.9 MB (16.43%)
 Tags: Array, Matrix
*/
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        auto same = [&](const vector<vector<int>>& a, const vector<vector<int>>& b) {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (a[i][j] != b[i][j]) return false;
            return true;
        };

        auto rot = [&](vector<vector<int>>& a) {
            vector<vector<int>> t(n, vector<int>(n));
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    t[j][n - 1 - i] = a[i][j];
            a = move(t);
        };

        for (int k = 0; k < 4; ++k) {
            if (same(mat, target)) return true;
            rot(mat);
        }

        return false;
    }
};