/*
 Problem: 3730. Maximum Subarray Sum After Multiplier
 Language: cpp
 Runtime: 46 ms (56.99%)
 Memory: 147.1 MB (45.28%)
 Tags: Array, Dynamic Programming
*/
class Solution {
private:
    long long solve(vector<int>& nums, int k, bool multiply) {
        const long long INF = 4e18;

        long long dp0 = 0;
        long long dp1 = -INF;
        long long dp2 = -INF;

        long long ans = -INF;

        for (const long long &x : nums) {
            long long y = multiply ? x * k : x / k;

            long long ndp0 = max(x, dp0 + x);
            long long ndp1 = max({y, dp0 + y, dp1 + y});
            long long ndp2 = max(dp1 + x, dp2 + x);

            dp0 = ndp0;
            dp1 = ndp1;
            dp2 = ndp2;

            ans = max({ans, dp1, dp2});
        }

        return ans;
    }

    long long kadane(vector<int>& nums) {
        long long cur = 0;
        long long ans = LLONG_MIN;

        for (const auto& x : nums) {
            cur = max((long long)x, cur + x);
            ans = max(ans, cur);
        }

        return ans;
    }

public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long ans = kadane(nums);

        ans = max(ans, solve(nums, k, true));
        ans = max(ans, solve(nums, k, false));

        return ans;
    }
};