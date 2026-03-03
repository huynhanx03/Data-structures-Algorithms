/*
 Problem: 4042. Minimum Operations to Transform Array
 Language: cpp
 Runtime: 40 ms (5.14%)
 Memory: 231 MB (5.14%)
 Tags: Array, Greedy
*/
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<long long> pre(n + 1), suff(n + 1);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = 1LL * pre[i] + 1LL * abs(nums1[i] - nums2[i]);
        }

        for (int i = n - 1; i >= 0; --i) {
            suff[i] = 1LL * suff[i + 1] + 1LL * abs(nums1[i] - nums2[i]);
        }

        long long ans = LLONG_MAX;
        
        for (int i = 0; i < n; ++i) {
            long long copy1 = abs(nums1[i] - nums2[n]);
            long long copy2 = abs(nums2[i] - nums2[n]);
            long long copy = -1;

            if ((nums1[i] <= nums2[n] && nums2[n] <= nums2[i]) || (nums1[i] >= nums2[n] && nums2[n] >= nums2[i])) {
                copy = 0;
            } else {
                copy = min(copy1, copy2);
            }
            
            long long cost = (long long) 1LL * pre[i] + 1LL * copy + 1LL * suff[i] + 1LL;
            ans = min(ans, cost);
        }

        return ans;
    }
};