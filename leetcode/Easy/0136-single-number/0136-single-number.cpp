/*
 Problem: 136. Single Number
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 20.7 MB (58.16%)
 Tags: Array, Bit Manipulation
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            ans ^= nums[i];
        }

        return ans;
    }
};