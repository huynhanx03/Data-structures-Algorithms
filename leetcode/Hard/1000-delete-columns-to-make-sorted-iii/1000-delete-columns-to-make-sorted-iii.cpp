/*
 Problem: 1000. Delete Columns to Make Sorted III
 Language: cpp
 Runtime: 4 ms (54.59%)
 Memory: 13.6 MB (47.93%)
 Tags: Array, String, Dynamic Programming
*/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        int m = strs.size();

        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                bool ok = true;
                for (int r = 0; r < m; r++) {
                    if (strs[r][j] > strs[r][i]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return n - *max_element(dp.begin(), dp.end());
    }
};
