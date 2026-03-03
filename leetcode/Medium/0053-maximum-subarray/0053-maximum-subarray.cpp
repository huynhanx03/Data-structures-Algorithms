/*
 Problem: 53. Maximum Subarray
 Language: cpp
 Runtime: 75 ms (5.20%)
 Memory: 70.6 MB (99.99%)
 Tags: Array, Divide and Conquer, Dynamic Programming
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans = -1e9;

        for (auto num : nums) {
            sum += num;

            ans = max(ans, max(sum, num));

            if (sum < 0)
                sum = 0;
        }

        return ans;
    }
};