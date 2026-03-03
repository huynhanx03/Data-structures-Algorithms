/*
 Problem: 3611. Construct the Minimum Bitwise Array II
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 28.1 MB (80.41%)
 Tags: Array, Bit Manipulation
*/
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (const auto& n : nums) {
            if ((n & 1) == 0) {
                ans.push_back(-1);
                continue;
            }
            int z = ((n + 1) & ~n) >> 1;
            ans.push_back(n & ~z);
        }
        return ans;
    }
};
