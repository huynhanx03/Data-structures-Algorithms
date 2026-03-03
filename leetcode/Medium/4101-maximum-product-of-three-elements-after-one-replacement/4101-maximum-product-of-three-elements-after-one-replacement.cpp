/*
 Problem: 4101. Maximum Product of Three Elements After One Replacement
 Language: cpp
 Runtime: 39 ms (59.65%)
 Memory: 124.4 MB (45.98%)
 Tags: Array, Math, Greedy, Sorting
*/
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        const long long mx = 1e5;

        return max({abs(mx * nums[0] * nums[1]), abs(mx * nums[0] * nums[n - 1]), abs(mx * nums[n - 1] * nums[n - 2])});
    }
};