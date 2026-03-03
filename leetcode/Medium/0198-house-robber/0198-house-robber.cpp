/*
 Problem: 198. House Robber
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 9.5 MB (100.00%)
 Tags: Array, Dynamic Programming
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n + 5, vector<int>(2));

        dp[0][0] = 0;
        dp[0][1] = nums[0];

        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};