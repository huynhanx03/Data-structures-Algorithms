/*
 Problem: 1. Two Sum
 Language: cpp
 Runtime: 7 ms (40.75%)
 Memory: 16.4 MB (5.20%)
 Tags: Array, Hash Table
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ans;

        map<int, int> pos;
        
        for (int i = 0; i < nums.size(); ++i)
            pos[nums[i]] = i;
        
        for (int i = 0; i < nums.size(); ++i) {
            int cur = target - nums[i];
            if (pos.count(cur)) {
                if (i == pos[cur]) continue;
                ans.push_back(i);
                ans.push_back(pos[cur]);
                break;
            }
        }
        return ans;
    }
};