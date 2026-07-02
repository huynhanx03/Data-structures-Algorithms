/*
 Problem: 3981. Jump Game IX
 Language: cpp
 Runtime: 63 ms (5.01%)
 Memory: 243.5 MB (5.02%)
 Tags: Array, Dynamic Programming
*/
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n), sz(n, 1), pref(n), suff(n), mx(n), ans(n);

        for (int i = 0; i < n; ++i) p[i] = i;

        auto find = [&](auto&& self, int x) -> int {
            while (x != p[x]) {
                p[x] = p[p[x]];
                x = p[x];
            }
            return x;
        };

        auto unite = [&](int a, int b) {
            a = find(find, a);
            b = find(find, b);
            if (a == b) return;
            if (sz[a] < sz[b]) swap(a, b);
            p[b] = a;
            sz[a] += sz[b];
        };

        pref[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = max(pref[i - 1], nums[i]);
        }

        suff[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suff[i] = min(suff[i + 1], nums[i]);
        }

        for (int i = 0; i + 1 < n; ++i) {
            if (pref[i] > suff[i + 1]) unite(i, i + 1);
        }

        for (int i = 0; i < n; ++i) mx[i] = nums[i];

        for (int i = 0; i < n; ++i) {
            int r = find(find, i);
            mx[r] = max(mx[r], nums[i]);
        }

        for (int i = 0; i < n; ++i) {
            ans[i] = mx[find(find, i)];
        }

        return ans;
    }
};