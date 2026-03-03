/*
 Problem: 4007. Maximum Total Subarray Value II
 Language: cpp
 Runtime: 491 ms (77.31%)
 Memory: 295 MB (31.93%)
 Tags: Array, Greedy, Segment Tree, Heap (Priority Queue)
*/
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        vector<int> velnorquis = nums;
        int n = nums.size();
        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;
        vector<vector<int>> st_max(LOG, vector<int>(n));
        vector<vector<int>> st_min(LOG, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            st_max[0][i] = nums[i];
            st_min[0][i] = nums[i];
        }
        for (int j = 1; j < LOG; ++j) {
            int len = 1 << j;
            int half = 1 << (j - 1);
            for (int i = 0; i + len <= n; ++i) {
                st_max[j][i] = max(st_max[j - 1][i], st_max[j - 1][i + half]);
                st_min[j][i] = min(st_min[j - 1][i], st_min[j - 1][i + half]);
            }
        }
        auto range = [&](int l, int r) -> pair<int,int> {
            int len = r - l + 1;
            int j = 31 - __builtin_clz(len);
            int half = 1 << j;
            int mx = max(st_max[j][l], st_max[j][r - half + 1]);
            int mn = min(st_min[j][l], st_min[j][r - half + 1]);
            return {mx, mn};
        };
        using T = tuple<long long,int,int>;
        priority_queue<T> pq;
        for (int l = 0; l < n; ++l) {
            auto [mx, mn] = range(l, n - 1);
            pq.emplace((long long)mx - mn, l, n - 1);
        }
        unordered_set<long long> vis;
        long long ans = 0;
        while (k > 0 && !pq.empty()) {
            auto [val, l, r] = pq.top(); pq.pop();
            long long key = 1LL * l * n + r;
            if (vis.count(key)) continue;
            vis.insert(key);
            ans += val;
            --k;
            if (r - 1 >= l) {
                auto [mx2, mn2] = range(l, r - 1);
                pq.emplace((long long)mx2 - mn2, l, r - 1);
            }
        }
        return ans;
    }
};
