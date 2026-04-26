/*
 Problem: 4270. Minimum Operations to Make Array Non Decreasing
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 136.8 MB (88.97%)
 Tags: None
*/
class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long ans = 0;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                ans += nums[i - 1] - nums[i];
                // ans = max(ans, (long long) nums[i - 1] - nums[i]);
                // nums[i] = nums[i - 1];
            }
        }

        return ans;
    }
};