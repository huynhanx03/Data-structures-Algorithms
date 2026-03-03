/*
 Problem: 54. Spiral Matrix
 Language: cpp
 Runtime: 1 ms (2.22%)
 Memory: 9.5 MB (14.40%)
 Tags: Array, Matrix, Simulation
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<bool>> check(n, vector<bool>(m, false));
        pair<int, int> dd[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int cd = 0, nd = 4;
        int i = 0, j = 0;
        vector<int> res;
        while (true) {
            res.push_back(matrix[i][j]);
            check[i][j] = true;
            int ni = i + dd[cd].first, nj = j + dd[cd].second;
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || check[ni][nj]) {
                cd = (cd + 1) % nd;
                ni = i + dd[cd].first;
                nj = j + dd[cd].second;
                if (ni < 0 || ni >= n || nj < 0 || nj >= m || check[ni][nj])
                    break;
            }
            i = ni;
            j = nj;
        }
        return res;
    }
};