/*
 Problem: 153. Find Minimum in Rotated Sorted Array
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 14.2 MB (10.98%)
 Tags: Array, Binary Search
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return nums[l];
    }
};