/*
 Problem: 2892. Check if Array is Good
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 26.4 MB (68.16%)
 Tags: Array, Hash Table, Sorting
*/
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (nums[n - 1] != n - 1) return false;

        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] != i + 1) return false;
        }

        return true;
    }
};