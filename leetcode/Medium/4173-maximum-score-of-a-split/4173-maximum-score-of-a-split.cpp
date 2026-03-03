/*
 Problem: 4173. Maximum Score of a Split
 Language: cpp
 Runtime: 19 ms (14.74%)
 Memory: 156.1 MB (39.94%)
 Tags: Array, Prefix Sum
*/
class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        vector <long long> pre(n + 5);
        vector <int> mn(n + 5);
        pre[0] = 0;
        mn[n + 1] = 2e9;
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] + nums[i - 1];
            // mn[n - i + 1] = min(mn[n - i + 2], nums[i - 1]); 
        }

        for (int i = n; i >= 1; --i) {
            mn[i] = min(mn[i + 1], nums[i - 1]);
        }

        long long ans = -2e18;
        for (int i = 1; i < n; ++i) {
            ans = max(ans, pre[i] - mn[i + 1]);
        }

        return ans;
    }
};