/*
 Problem: 2714. Left and Right Sum Differences
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 15 MB (53.32%)
 Tags: Array, Prefix Sum
*/
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int s = accumulate(nums.begin(), nums.end(), 0);
        int l = 0;

        vector<int> ans(n);

        for (int i = 0; i < n; ++i) {
            s -= nums[i];
            ans[i] = abs(l - s);
            l += nums[i];
        }

        return ans;
    }
};