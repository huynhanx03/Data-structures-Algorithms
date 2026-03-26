/*
 Problem: 3850. Equal Sum Grid Partition II
 Language: cpp
 Runtime: 1061 ms (46.15%)
 Memory: 432.9 MB (40.00%)
 Tags: Array, Hash Table, Matrix, Enumeration, Prefix Sum
*/
class Solution {
private:
    bool ok(unordered_map<long long,int>& freq, vector<vector<int>>& g,
            int r1, int r2, int c1, int c2, long long diff) {

        int h = r2 - r1 + 1, w = c2 - c1 + 1;

        if (h * w == 1) {
            return 0;
        }
        if (h == 1) {
            return g[r1][c1] == diff || g[r1][c2] == diff;
        }
        if (w == 1) {
            return g[r1][c1] == diff || g[r2][c1] == diff;
        }

        return freq.count(diff);
    }

public:
    bool canPartitionGrid(vector<vector<int>>& g) {
        int rows = g.size(), cols = g[0].size();
        long long total = 0, cur = 0;

        unordered_map<long long,int> top, bot, left, right;

        for (const auto& row : g) {
            for (const auto& val : row) {
                total += val;
                ++bot[val];
                ++right[val];
            }
        }

        for (int r = 0; r < rows - 1; ++r) {
            for (int c = 0; c < cols; ++c) {
                const auto& val = g[r][c];

                cur += val;
                ++top[val];

                if (--bot[val] == 0) {
                    bot.erase(val);
                }
            }

            long long other = total - cur;
            if (cur == other) {
                return 1;
            }

            long long diff = abs(cur - other);

            if (cur > other) {
                if (ok(top, g, 0, r, 0, cols - 1, diff)) {
                    return 1;
                }
            } else {
                if (ok(bot, g, r + 1, rows - 1, 0, cols - 1, diff)) {
                    return 1;
                }
            }
        }

        cur = 0;

        for (int c = 0; c < cols - 1; ++c) {
            for (int r = 0; r < rows; ++r) {
                const auto& val = g[r][c];

                cur += val;
                ++left[val];

                if (--right[val] == 0) {
                    right.erase(val);
                }
            }

            long long other = total - cur;
            if (cur == other) {
                return 1;
            }

            long long diff = abs(cur - other);

            if (cur > other) {
                if (ok(left, g, 0, rows - 1, 0, c, diff)) {
                    return 1;
                }
            } else {
                if (ok(right, g, 0, rows - 1, c + 1, cols - 1, diff)) {
                    return 1;
                }
            }
        }

        return 0;
    }
};