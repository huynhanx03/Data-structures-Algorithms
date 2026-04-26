/*
 Problem: 4290. Valid Elements in an Array
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 32.3 MB (44.02%)
 Tags: None
*/
class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        vector<int> suf(n + 1, INT_MIN);
        
        for (int i = n - 1; i >= 0; --i) {
            suf[i] = max(suf[i + 1], nums[i]);
        }

        int pre = INT_MIN;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] > pre || nums[i] > suf[i + 1]) ans.push_back(nums[i]);

            pre = max(pre, nums[i]);
        }
        
        return ans;
    }
};