/*
 Problem: 4152. Minimum Subarray Length With Distinct Sum At Least K
 Language: cpp
 Runtime: 503 ms (16.09%)
 Memory: 289.1 MB (36.67%)
 Tags: Array, Hash Table, Sliding Window
*/
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        long long sum = 0;
        map<int, int> cnt;
        int ans = n + 1;

        for (int r = 0; r < n; ++r) {
            if (cnt[nums[r]] == 0) {
                sum += nums[r];
            }

            ++cnt[nums[r]];

            while (sum >= k) {
                ans = min(ans, r - l + 1);
                --cnt[nums[l]];

                if (cnt[nums[l]] == 0) {
                    sum -= nums[l];
                }
                ++l;
            }
        }
        
        return (ans == n + 1) ? -1 : ans;
    }
};