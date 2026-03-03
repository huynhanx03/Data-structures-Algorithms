/*
 Problem: 4078. Maximum Alternating Sum of Squares
 Language: cpp
 Runtime: 59 ms (57.67%)
 Memory: 176.3 MB (34.01%)
 Tags: Array, Greedy, Sorting
*/
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (auto& x : nums) x = abs(x);
        sort(nums.begin(), nums.end());

        int n = nums.size();

        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            if (i < n / 2) ans -= nums[i] * nums[i];
            else ans += nums[i] * nums[i];
        }

        return ans;
    }
};