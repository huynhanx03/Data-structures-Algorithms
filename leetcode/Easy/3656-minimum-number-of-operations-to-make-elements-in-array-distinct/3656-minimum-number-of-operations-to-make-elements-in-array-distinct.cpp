/*
 Problem: 3656. Minimum Number of Operations to Make Elements in Array Distinct
 Language: cpp
 Runtime: 3 ms (62.87%)
 Memory: 28.2 MB (43.38%)
 Tags: Array, Hash Table
*/
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int, pair<int, int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]].first = -1;
            } else {
                mp[nums[i]].first = mp[nums[i]].second;
            }
            mp[nums[i]].second = i;
        }

        int mx = 0;

        for (const auto& [v, p]: mp) {
            mx = max(mx, p.first + 1);
        }

        return mx / 3 + (mx % 3 != 0);
    }
};