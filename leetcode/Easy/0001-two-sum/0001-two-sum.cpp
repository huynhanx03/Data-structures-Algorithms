/*
 Problem: 1. Two Sum
 Language: cpp
 Runtime: 1112 ms (5.24%)
 Memory: 10.1 MB (100.00%)
 Tags: Array, Hash Table
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ans;
        for (int i = 0; i < nums.size(); ++i)
            for (int j = i + 1; j < nums.size(); ++j) 
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
        return ans;
    }
};