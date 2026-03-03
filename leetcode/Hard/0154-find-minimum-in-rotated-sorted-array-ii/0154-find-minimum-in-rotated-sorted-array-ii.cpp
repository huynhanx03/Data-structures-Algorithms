/*
 Problem: 154. Find Minimum in Rotated Sorted Array II
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 15.9 MB (99.61%)
 Tags: Array, Binary Search
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == nums[r]) {
                --r;
            } else if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return nums[l];
    }
};