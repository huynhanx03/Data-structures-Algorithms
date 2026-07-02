/*
 Problem: 2639. Separate the Digits in an Array
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 15.3 MB (58.98%)
 Tags: Array, Simulation
*/
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for (const auto& x : nums) {
            string s = to_string(x);

            for (const auto& c : s) {
                ans.push_back(c - '0');
            }
        }

        return ans;
    }
};