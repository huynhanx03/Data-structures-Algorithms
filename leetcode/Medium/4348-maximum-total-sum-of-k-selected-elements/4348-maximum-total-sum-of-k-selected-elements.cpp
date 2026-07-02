/*
 Problem: 4348. Maximum Total Sum of K Selected Elements
 Language: cpp
 Runtime: 72 ms (43.25%)
 Memory: 186.3 MB (43.67%)
 Tags: Array, Greedy, Sorting
*/
class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long ans = 0;

        sort(nums.begin(), nums.end(), greater<>());

        for (int i = 0; i < k; ++i) ans += 1ll * nums[i] * (mul > 0 ? mul-- : 1);
        
        return ans;
    }
};