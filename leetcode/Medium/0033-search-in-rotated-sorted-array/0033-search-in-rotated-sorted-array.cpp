/*
 Problem: 33. Search in Rotated Sorted Array
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 15.3 MB (34.54%)
 Tags: Array, Binary Search
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (nums[m] == target)
                return m;

            if (nums[m] >= nums[l]) {
                if (nums[l] <= target && target <= nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            } else {
                if (nums[m] <= target && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }

        return -1;
    }
};