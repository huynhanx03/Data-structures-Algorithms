/*
 Problem: 1612. Avoid Flood in The City
 Language: cpp
 Runtime: 188 ms (21.29%)
 Memory: 117.1 MB (99.71%)
 Tags: Array, Hash Table, Binary Search, Greedy, Heap (Priority Queue)
*/
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        map<int, int> mp;
        set<int> dryDays;
        for (int i = 0; i < n; ++i) {
            if (rains[i] == 0) {
                dryDays.insert(i);
            } else {
                int lake = rains[i];
                if (mp.count(lake)) {
                    auto it = dryDays.lower_bound(mp[lake]);
                    if (it == dryDays.end()) return {};
                    ans[*it] = lake;
                    dryDays.erase(it);
                }
                mp[lake] = i;
                ans[i] = -1;
            }
        }
        return ans;
    }
};
