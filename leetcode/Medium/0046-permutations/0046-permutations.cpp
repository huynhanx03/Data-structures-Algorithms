/*
 Problem: 46. Permutations
 Language: cpp
 Runtime: 9 ms (5.96%)
 Memory: 11.2 MB (21.03%)
 Tags: Array, Backtracking
*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<bool> check;

    void backtrack(vector<int>& nums, int& n, int cnt, vector<int> res) {
        if (cnt >= n) {
            ans.push_back(res);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (check[i])
                continue;
            
            check[i] = 1;
            res.push_back(nums[i]);

            backtrack(nums, n, cnt + 1, res);

            check[i] = 0;
            res.pop_back();
        }        
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        check.resize(n, 0);

        backtrack(nums, n, 0, vector<int>());

        return ans;
    }
};