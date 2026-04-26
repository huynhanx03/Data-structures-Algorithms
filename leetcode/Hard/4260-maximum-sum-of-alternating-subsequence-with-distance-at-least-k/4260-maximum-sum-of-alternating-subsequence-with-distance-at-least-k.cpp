/*
 Problem: 4260. Maximum Sum of Alternating Subsequence With Distance at Least K
 Language: cpp
 Runtime: 415 ms (79.75%)
 Memory: 283 MB (83.13%)
 Tags: None
*/
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int M = vals.size();

        auto get_idx = [&](int x) {
            return lower_bound(vals.begin(), vals.end(), x) - vals.begin();
        };

        const long long MIN_INF = -1e18;
        vector<long long> treePeak(2 * M, MIN_INF);
        vector<long long> treeValley(2 * M, MIN_INF);

        auto update = [&](vector<long long>& tree, int p, long long val) {
            p += M;
            tree[p] = max(tree[p], val);
            for (p >>= 1; p > 0; p >>= 1) {
                tree[p] = max(tree[p << 1], tree[(p << 1) | 1]);
            }
        };

        auto query = [&](const vector<long long>& tree, int l, int r) {
            if (l > r) return MIN_INF;
            long long res = MIN_INF;
            for (l += M, r += M + 1; l < r; l >>= 1, r >>= 1) {
                if (l & 1) res = max(res, tree[l++]);
                if (r & 1) res = max(res, tree[--r]);
            }
            return res;
        };

        vector<long long> dpPeak(n, MIN_INF);
        vector<long long> dpValley(n, MIN_INF);
        long long ans = MIN_INF;

        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                int prev_idx = get_idx(nums[i - k]);
                update(treeValley, prev_idx, dpValley[i - k]);
                update(treePeak, prev_idx, dpPeak[i - k]);
            }

            int c = get_idx(nums[i]);
            long long val = nums[i];

            long long bestV = query(treeValley, 0, c - 1);
            dpPeak[i] = val + max(0LL, bestV);

            long long bestP = query(treePeak, c + 1, M - 1);
            dpValley[i] = val + max(0LL, bestP);

            ans = max({ans, dpPeak[i], dpValley[i]});
        }

        return ans;
    }
};