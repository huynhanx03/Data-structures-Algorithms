/*
 Problem: 3778. Transform Array by Parity
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 28.1 MB (86.47%)
 Tags: Array, Sorting, Counting
*/
class Solution {
public:
    vector<int> transformArray(vector<int>& nums)
        {
        for (int& num : nums) {
            if (num % 2 == 0) {
                num = 0; 
            } else {
                num = 1;  
            }
        }
        sort(nums.begin(), nums.end()); 
        return nums;
    }
};