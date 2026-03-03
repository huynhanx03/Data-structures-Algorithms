/*
 Problem: 4107. Find Missing Elements
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 32.3 MB (53.84%)
 Tags: Array, Hash Table, Sorting
*/
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<bool> mp(105, false);
        int mn = 105;
        int mx = 1;
        
        for (const auto& x : nums) {
            mp[x] = true;
            mn = min(mn, x);
            mx = max(mx, x);
        }

        vector <int> ans;

        for (int x = mn; x <= mx; ++x) {
            if (!mp[x])
                ans.push_back(x);
        }

        return ans;
    }
};