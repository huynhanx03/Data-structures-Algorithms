/*
 Problem: 3263. Divide an Array Into Subarrays With Minimum Cost I
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 30.6 MB (45.03%)
 Tags: Array, Sorting, Enumeration
*/
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int minPrefix = nums[1];
        int ans = INT_MAX;
        
        for (int i = 2; i < nums.size(); i++) {
            ans = min(ans, nums[0] + minPrefix + nums[i]);
            minPrefix = min(minPrefix, nums[i]);
        }
        
        return ans;
    }
};
