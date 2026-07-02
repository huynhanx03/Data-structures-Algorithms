/*
 Problem: 4312. Limit Occurrences in Sorted Array
 Language: cpp
 Runtime: 3 ms (37.23%)
 Memory: 34.2 MB (5.31%)
 Tags: Array, Two Pointers
*/
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int>cnt(105, 0);
        vector<int> ans;
        
        for (const auto& x : nums) {
            ++cnt[x];

            if (cnt[x] <= k) ans.push_back(x);
        }

        return ans;
    }
};