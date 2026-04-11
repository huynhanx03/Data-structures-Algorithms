/*
 Problem: 4119. Minimum Distance Between Three Equal Elements II
 Language: cpp
 Runtime: 551 ms (28.75%)
 Memory: 348.2 MB (44.75%)
 Tags: Array, Hash Table
*/
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> mp;
        int ans = 1e9;

        for (int i = 0; i < nums.size(); ++i)
            mp[nums[i]].push_back(i);

        for (auto& [x, v]: mp) {
            if (v.size() < 3) continue;
            
            sort(v.begin(), v.end());

            for (int i = 0; i + 2 < v.size(); ++i) {
                ans = min(ans, v[i + 2] - v[i]);
            }
        }

        return ans == 1e9 ? -1 : ans * 2;
    }
};