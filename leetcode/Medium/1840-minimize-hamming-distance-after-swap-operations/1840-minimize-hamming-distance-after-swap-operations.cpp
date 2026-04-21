/*
 Problem: 1840. Minimize Hamming Distance After Swap Operations
 Language: cpp
 Runtime: 142 ms (72.25%)
 Memory: 154 MB (44.50%)
 Tags: Array, Depth-First Search, Union-Find
*/
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int> p(n), sz(n, 1);
        iota(p.begin(), p.end(), 0);

        auto find = [&](int x) {
            while (x != p[x]) {
                p[x] = p[p[x]];
                x = p[x];
            }
            return x;
        };

        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return;
            if (sz[a] < sz[b]) swap(a, b);
            p[b] = a;
            sz[a] += sz[b];
        };

        for (const auto& e : allowedSwaps) unite(e[0], e[1]);

        unordered_map<int, unordered_map<int, int>> mp;
        for (int i = 0; i < n; ++i) ++mp[find(i)][source[i]];

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int r = find(i);
            if (mp[r][target[i]] > 0) {
                --mp[r][target[i]];
            } else {
                ++ans;
            }
        }

        return ans;
    }
};