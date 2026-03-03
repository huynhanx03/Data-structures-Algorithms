/*
 Problem: 4158. Absolute Difference Between Maximum and Minimum K Elements
 Language: cpp
 Runtime: 4 ms (8.87%)
 Memory: 32.3 MB (15.71%)
 Tags: Array, Sorting
*/
class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int res = 0;
        int n = nums.size();

        for (int i = 0; i < k; ++i) {
            res += nums[i];
            res -= nums[n - i - 1];
        }

        return abs(res);
    }
};