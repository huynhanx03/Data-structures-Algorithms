/*
 Problem: 1878. Check if Array Is Sorted and Rotated
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 11.4 MB (19.33%)
 Tags: Array
*/
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        int drops = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[(i + 1) % n]) {
                drops++;
            }
        }

        return drops <= 1;
    }
};