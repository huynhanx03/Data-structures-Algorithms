/*
 Problem: 396. Rotate Function
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 99.6 MB (51.07%)
 Tags: Array, Math, Dynamic Programming
*/
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0, f = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            f += 1LL * i * nums[i];
        }

        long long ans = f;
        for (int k = 1; k < n; ++k) {
            f = f + sum - 1LL * n * nums[n - k];
            ans = max(ans, f);
        }

        return (int)ans;
    }
};