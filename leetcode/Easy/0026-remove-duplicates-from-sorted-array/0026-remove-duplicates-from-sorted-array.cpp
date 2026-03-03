/*
 Problem: 26. Remove Duplicates from Sorted Array
 Language: cpp
 Runtime: 11 ms (5.07%)
 Memory: 21.4 MB (100.00%)
 Tags: Array, Two Pointers
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                ++k;
            }
        }

        return k;
    }
};