/*
 Problem: 3653. Maximum Subarray Sum With Length Divisible by K
 Language: cpp
 Runtime: 4 ms (84.96%)
 Memory: 162.2 MB (54.75%)
 Tags: Array, Hash Table, Prefix Sum
*/
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> minPref(k, LLONG_MAX);
        long long pref = 0, res = LLONG_MIN;
        
        minPref[0] = 0;
        for (int i = 0; i < n; i++) {
            pref += nums[i];
            int m = (i + 1) % k;
            if (minPref[m] != LLONG_MAX)
                res = max(res, pref - minPref[m]);
            minPref[m] = min(minPref[m], pref);
        }
        return res;
    }
};