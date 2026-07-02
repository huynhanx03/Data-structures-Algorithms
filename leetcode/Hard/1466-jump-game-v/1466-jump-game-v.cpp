/*
 Problem: 1466. Jump Game V
 Language: cpp
 Runtime: 12 ms (52.67%)
 Memory: 19.1 MB (56.81%)
 Tags: Array, Dynamic Programming, Sorting
*/
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);

        auto dfs = [&](auto&& self, int i) -> int {

            if (dp[i] != -1)
                return dp[i];

            int ans = 1;

            for (int j = i - 1; j >= max(0, i - d); --j) {

                if (arr[j] >= arr[i])
                    break;

                ans = max(ans, 1 + self(self, j));
            }

            for (int j = i + 1; j <= min(n - 1, i + d); ++j) {

                if (arr[j] >= arr[i])
                    break;

                ans = max(ans, 1 + self(self, j));
            }

            return dp[i] = ans;
        };

        int res = 1;

        for (int i = 0; i < n; ++i) {
            res = max(res, dfs(dfs, i));
        }

        return res;
    }
};