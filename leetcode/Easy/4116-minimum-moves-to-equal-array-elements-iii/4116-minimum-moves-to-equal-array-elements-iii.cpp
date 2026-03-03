/*
 Problem: 4116. Minimum Moves to Equal Array Elements III
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 31.5 MB (81.77%)
 Tags: Array, Math
*/
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = 0;
        for (const auto& x : nums) {
            mx = max(mx, x);
        }

        int ans = 0;

        for (const auto& x : nums) {
           ans += mx - x;
        }

        return ans;
    }
};