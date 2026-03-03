/*
 Problem: 4098. Longest Non-Decreasing Subarray After Replacing at Most One Element
 Language: cpp
 Runtime: 47 ms (11.17%)
 Memory: 190.1 MB (58.20%)
 Tags: Array, Dynamic Programming
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n, 1), right(n, 1);

        for (int i = 1; i < n; ++i) {
            if (nums[i] >= nums[i - 1]) left[i] = left[i - 1] + 1;
        }

        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] <= nums[i + 1]) right[i] = right[i + 1] + 1;
        }

        int ans = *max_element(left.begin(), left.end());

        for (int i = 0; i < n; ++i) {
            int tmp = 1;
            if (i > 0) tmp += left[i - 1];
            if (i < n - 1) tmp += right[i + 1];

            if (i > 0 && i < n - 1 && nums[i - 1] > nums[i + 1]) {
                tmp = max({
                   (i > 0 ? left[i - 1] + 1 : 1),
                    (i < n - 1 ? right[i + 1] + 1 : 1)
                });
            }

            ans = max(ans, tmp);
        }

        return ans;
    }
};