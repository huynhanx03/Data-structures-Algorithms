/*
 Problem: 4145. Minimum Inversion Count in Subarrays of Fixed Length
 Language: cpp
 Runtime: 251 ms (87.28%)
 Memory: 187.1 MB (87.28%)
 Tags: Array, Segment Tree, Sliding Window
*/
struct Fenwick {
    int n;
    vector <long long> bit;
    Fenwick(int n): n(n), bit(n + 1, 0) {}

    void update(int i, int v) {
        for (; i <= n; i += i & -i) bit[i] += v;
    }

    long long query(int i) {
        long long s = 0;
        for (; i > 0; i -= i & -i) s += bit[i];

        return s;
    }

    long long query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

class Solution {
public:
    long long minInversionCount(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> comp = nums;
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());

        auto get = [&](int x) {
            return lower_bound(comp.begin(), comp.end(), x) - comp.begin() + 1;
        };

        int m = comp.size();
        Fenwick fw(m);

        long long inv = 0;
        long long ans = LLONG_MAX;
        
        for (int i = 0; i < k; ++i) {
            int v = get(nums[i]);
            inv += fw.query(v + 1, m);
            fw.update(v, 1);
        }
        ans = min(ans, inv);
        for (int i = k; i < n; ++i) {
            int add = get(nums[i]);
            int rem = get(nums[i - k]);

            inv -= fw.query(1, rem - 1);
            fw.update(rem, -1);

            inv += fw.query(add + 1, m);
            fw.update(add, 1);

            ans = min(ans, inv);
        }

        return ans;
    }
};