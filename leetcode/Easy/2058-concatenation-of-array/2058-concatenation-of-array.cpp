/*
 Problem: 2058. Concatenation of Array
 Language: cpp
 Runtime: 3 ms (10.36%)
 Memory: 16.7 MB (94.77%)
 Tags: Array, Simulation
*/
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n * 2);

        for (int i = 0; i < n; ++i) {
            ans[i] = nums[i];
            ans[i + n] = ans[i];
        }

        return ans;
    }
};