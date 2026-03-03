/*
 Problem: 238. Product of Array Except Self
 Language: cpp
 Runtime: 23 ms (5.27%)
 Memory: 39.9 MB (99.79%)
 Tags: Array, Prefix Sum
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int x = 1, cnt0 = 0;

        vector <int> ans;

        for (auto &num: nums) {
            if (num != 0)
                x *= num;
            else
                ++cnt0;
        }

        for (auto& num: nums) {
            if (num == 0) {
                if (cnt0 > 1) 
                    ans.push_back(0);
                else
                    ans.push_back(x);
            } else {
                if (cnt0 > 0)
                    ans.push_back(0);
                else
                    ans.push_back(x / num);
            }
        }
        
        return ans;
    }
};