/*
 Problem: 1388. Greatest Sum Divisible by Three
 Language: cpp
 Runtime: 3 ms (84.60%)
 Memory: 28.8 MB (93.16%)
 Tags: Array, Dynamic Programming, Greedy, Sorting
*/
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);
        dp[1] = dp[2] = INT_MIN;
        for (const auto& x : nums) {
            int a = dp[0], b = dp[1], c = dp[2];

            int newSum0 = a + x;
            int r = newSum0 % 3;

            if (r == 0) dp[0] = max(dp[0], newSum0);
            else if (r == 1) dp[1] = max(dp[1], newSum0);
            else dp[2] = max(dp[2], newSum0);

            if (b != INT_MIN) {
                int newSum1 = b + x;
                int r1 = newSum1 % 3;
                dp[r1] = max(dp[r1], newSum1);
            }

            if (c != INT_MIN) {
                int newSum2 = c + x;
                int r2 = newSum2 % 3;
                dp[r2] = max(dp[r2], newSum2);
            }
        }

        return dp[0];
    }
};