/*
 Problem: 35. Search Insert Position
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 13.7 MB (42.56%)
 Tags: Array, Binary Search
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] >= target) 
                right = mid - 1;
            else 
                left = mid + 1;
        }

        return left;
    }
};