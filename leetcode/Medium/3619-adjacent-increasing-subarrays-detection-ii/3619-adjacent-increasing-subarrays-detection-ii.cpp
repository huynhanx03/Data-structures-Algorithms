/*
 Problem: 3619. Adjacent Increasing Subarrays Detection II
 Language: cpp
 Runtime: 222 ms (69.52%)
 Memory: 189.5 MB (12.75%)
 Tags: Array, Binary Search
*/
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return 0;
        vector<int> left(n, 1), right(n, 1);
        for (int i = 1; i < n; ++i)
            if (nums[i] > nums[i - 1])
                left[i] = left[i - 1] + 1;
        for (int i = n - 2; i >= 0; --i)
            if (nums[i] < nums[i + 1])
                right[i] = right[i + 1] + 1;
        int ans = 0;
        for (int i = 1; i < n; ++i)
            ans = max(ans, min(left[i - 1], right[i]));
        return ans;
    }
};
