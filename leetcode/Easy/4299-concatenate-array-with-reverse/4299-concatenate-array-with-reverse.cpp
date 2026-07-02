/*
 Problem: 4299. Concatenate Array With Reverse
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 30.3 MB (64.83%)
 Tags: Array, Simulation
*/
class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> ans = nums;;

        for (int i = nums.size() - 1; i >= 0; --i) ans.push_back(nums[i]);

        return ans;
    }
};