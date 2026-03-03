/*
 Problem: 792. Binary Search
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 31.3 MB (80.16%)
 Tags: Array, Binary Search
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return -1;
    }
};