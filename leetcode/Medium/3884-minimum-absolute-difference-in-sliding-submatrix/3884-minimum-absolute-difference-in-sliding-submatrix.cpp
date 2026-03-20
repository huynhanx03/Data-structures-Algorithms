/*
 Problem: 3884. Minimum Absolute Difference in Sliding Submatrix
 Language: cpp
 Runtime: 33 ms (46.67%)
 Memory: 36.3 MB (45.93%)
 Tags: Array, Sorting, Matrix
*/
class Solution {
public:
    int getMinDiff(const multiset<int>& ms) {
        if (ms.size() <= 1) return 0;

        int res = INT_MAX;
        auto it = ms.begin();
        auto prev = it++;

        for (; it != ms.end(); ++it, ++prev) {
            if (*it != *prev) {
                res = min(res, *it - *prev);
            }
        }

        return res == INT_MAX ? 0 : res;
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; ++i) {
            multiset<int> ms;

            for (int x = i; x < i + k; ++x) {
                for (int y = 0; y < k; ++y) {
                    ms.insert(grid[x][y]);
                }
            }

            ans[i][0] = getMinDiff(ms);

            for (int j = 1; j <= n - k; ++j) {
                for (int x = i; x < i + k; ++x) {
                    ms.erase(ms.find(grid[x][j - 1]));
                }
                for (int x = i; x < i + k; ++x) {
                    ms.insert(grid[x][j + k - 1]);
                }
                ans[i][j] = getMinDiff(ms);
            }
        }

        return ans;
    }
};