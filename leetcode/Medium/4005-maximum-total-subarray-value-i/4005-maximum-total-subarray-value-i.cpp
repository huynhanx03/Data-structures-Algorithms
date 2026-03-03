/*
 Problem: 4005. Maximum Total Subarray Value I
 Language: cpp
 Runtime: 3 ms (39.82%)
 Memory: 108.4 MB (1.37%)
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
