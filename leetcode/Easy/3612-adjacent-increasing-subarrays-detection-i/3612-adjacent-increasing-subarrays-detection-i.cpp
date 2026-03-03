/*
 Problem: 3612. Adjacent Increasing Subarrays Detection I
 Language: cpp
 Runtime: 13 ms (51.47%)
 Memory: 41.5 MB (5.72%)
 Tags: Array
*/
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2 * k) return false;

        vector<int> cnt(n, 0);
        cnt[0] = 1;

        for (int i = 1; i < n; ++i) {
            cnt[i] = nums[i] > nums[i - 1] ? cnt[i - 1] + 1 : 1;
        }

        for (int i = k - 1; i <= n - k - 1; ++i) {
            if (cnt[i] >= k && cnt[i + k] >= k) {
                return true;
            }
        }

        return false;
    }
};
