/*
 Problem: 632. Smallest Range Covering Elements from K Lists
 Language: cpp
 Runtime: 67 ms (84.42%)
 Memory: 47.9 MB (48.55%)
 Tags: Array, Hash Table, Greedy, Sliding Window, Sorting, Heap (Priority Queue)
*/
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> ordered; // (number, group)
        for (size_t k = 0; k < nums.size(); ++k)
            for (auto n: nums[k]) ordered.push_back({n, k});
        sort(ordered.begin(), ordered.end());

        int i = 0, k = 0;
        vector<int> ans;
        unordered_map<int, int> count;
        for (size_t j = 0; j < ordered.size(); ++j) {
            if (!count[ordered[j].second]) ++k;
            ++count[ordered[j].second];
            if (k == nums.size()) { 
                while (count[ordered[i].second] > 1) --count[ordered[i++].second];
                if (ans.empty() || ans[1] - ans[0] > ordered[j].first - ordered[i].first) {
                    ans = vector<int>{ordered[i].first, ordered[j].first};
                }
            }
        }

        return ans;
    }
};