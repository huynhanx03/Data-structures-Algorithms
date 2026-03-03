/*
 Problem: 27. Remove Element
 Language: cpp
 Runtime: 5 ms (0.31%)
 Memory: 10.7 MB (100.00%)
 Tags: Array, Two Pointers
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        
        for (int i = 0; i < nums.size(); ++i) 
            if (nums[i] != val) {
                nums[k] = nums[i];
                ++k;
            }
        
        return k;
    }
};