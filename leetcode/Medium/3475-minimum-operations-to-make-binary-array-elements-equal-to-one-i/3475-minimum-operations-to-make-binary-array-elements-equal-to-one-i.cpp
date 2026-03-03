/*
 Problem: 3475. Minimum Operations to Make Binary Array Elements Equal to One I
 Language: cpp
 Runtime: 4 ms (84.83%)
 Memory: 139.9 MB (82.39%)
 Tags: Array, Bit Manipulation, Queue, Sliding Window, Prefix Sum
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] == 0) {
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                count++;
            }
        }
        
        return (nums[n - 2] == 1 && nums[n - 1] == 1) ? count : -1;
    }
};