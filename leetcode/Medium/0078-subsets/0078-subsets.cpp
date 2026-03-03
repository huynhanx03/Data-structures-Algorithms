/*
 Problem: 78. Subsets
 Language: cpp
 Runtime: 3 ms (30.32%)
 Memory: 14.4 MB (19.89%)
 Tags: Array, Backtracking, Bit Manipulation
*/
class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, vector<int> res, int idx, int& n) {
        if (idx == n) {
            ans.push_back(res);
            return;
        }

        backtrack(nums, res, idx + 1, n);

        res.push_back(nums[idx]);

        backtrack(nums, res, idx + 1, n);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        backtrack(nums, vector<int>(), 0, n);

        return ans;
    }
};