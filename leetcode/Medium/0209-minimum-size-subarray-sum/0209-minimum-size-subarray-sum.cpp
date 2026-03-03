/*
 Problem: 209. Minimum Size Subarray Sum
 Language: cpp
 Runtime: 25 ms (4.82%)
 Memory: 30.4 MB (100.00%)
 Tags: Array, Binary Search, Sliding Window, Prefix Sum
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int ans = n + 1;
        int sum = 0;

        while (r < n && sum < target) {
            sum += nums[r];
            
            if (sum >= target)
                while (sum >= target) {
                    sum -= nums[l];
                    ans = min(ans, r - l + 1);
                    ++l;
                }

            ++r;
        }

        return ans == n + 1 ? 0 : ans;
    } 
};