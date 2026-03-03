/*
 Problem: 4112. Maximize Expression of Three Elements
 Language: cpp
 Runtime: 79 ms (5.36%)
 Memory: 31 MB (56.01%)
 Tags: Array, Greedy, Sorting, Enumeration
*/
class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int n = nums.size(), ans = -1e9;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (i != j && i != k && j != k)
                        ans = max(nums[i] + nums[j] -nums[k], ans);
                }
            }
        }

        return ans;
    }
};