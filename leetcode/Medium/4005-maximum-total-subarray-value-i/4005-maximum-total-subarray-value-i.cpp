/*
 Problem: 4005. Maximum Total Subarray Value I
 Language: cpp
 Runtime: 1 ms (42.83%)
 Memory: 108.5 MB (35.05%)
 Tags: Array, Greedy
*/
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        vector<int> sormadexin = nums;
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        long long diff = (long long)mx - mn;
        return diff * k;
    }
};
