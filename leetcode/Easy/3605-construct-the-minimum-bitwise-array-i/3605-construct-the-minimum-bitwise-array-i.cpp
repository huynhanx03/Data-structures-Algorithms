/*
 Problem: 3605. Construct the Minimum Bitwise Array I
 Language: cpp
 Runtime: 4 ms (20.24%)
 Memory: 25.3 MB (7.38%)
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
