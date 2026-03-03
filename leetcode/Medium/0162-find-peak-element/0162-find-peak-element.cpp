/*
 Problem: 162. Find Peak Element
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 12.7 MB (32.55%)
 Tags: Array, Binary Search
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if ((mid == 0 || nums[mid] >= nums[mid - 1]) && (mid == n - 1 || nums[mid] >= nums[mid + 1])) return mid;

            if (nums[mid] < nums[mid + 1]) l = mid + 1;
            else r = mid - 1;
        }

        return -1;
    }
};