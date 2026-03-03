/*
 Problem: 34. Find First and Last Position of Element in Sorted Array
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 17.6 MB (53.99%)
 Tags: Array, Binary Search
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        return {BS(nums, target, 0, n-1, true), BS(nums, target, 0, n-1, false)};
    }

private:
    int BS(vector<int>& nums, int target, int l, int r, bool isLeft) {
        int result = -1;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            
            if (nums[m] == target) {
                result = m;                  

                if (isLeft)
                    r = m - 1;
                else
                    l = m + 1;
            } else if (nums[m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return result;
    }
};