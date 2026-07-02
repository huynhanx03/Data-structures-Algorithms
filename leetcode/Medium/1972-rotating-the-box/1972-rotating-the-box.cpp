/*
 Problem: 1972. Rotating the Box
 Language: cpp
 Runtime: 11 ms (63.34%)
 Memory: 56.9 MB (11.42%)
 Tags: Array, Two Pointers, Matrix
*/
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));

        for (int i = 0; i < m; ++i) {
            int pos = n - 1;
            for (int j = n - 1; j >= 0; --j) {
                if (boxGrid[i][j] == '*') {
                    ans[j][m - 1 - i] = '*';
                    pos = j - 1;
                } else if (boxGrid[i][j] == '#') {
                    ans[pos][m - 1 - i] = '#';
                    --pos;
                }
            }
        }

        return ans;
    }
};