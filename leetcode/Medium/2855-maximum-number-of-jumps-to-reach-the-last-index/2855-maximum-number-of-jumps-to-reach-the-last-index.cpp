/*
 Problem: 2855. Maximum Number of Jumps to Reach the Last Index
 Language: cpp
 Runtime: 19 ms (57.09%)
 Memory: 68.5 MB (40.94%)
 Tags: Array, Dynamic Programming
*/
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            if (dp[i] == -1) continue;

            for (int j = i + 1; j < n; ++j) {
                if (abs(nums[j] - nums[i]) <= target) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};