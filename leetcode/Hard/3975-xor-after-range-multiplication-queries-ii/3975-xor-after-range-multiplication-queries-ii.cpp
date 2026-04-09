/*
 Problem: 3975. XOR After Range Multiplication Queries II
 Language: cpp
 Runtime: 623 ms (23.53%)
 Memory: 618.8 MB (9.41%)
 Tags: Array, Divide and Conquer
*/
class Solution {
public:
    int xorAfterQueries(vector<int>& a, vector<vector<int>>& qs) {
        const int MOD = 1e9 + 7;
        int n = a.size();
        int B = sqrt(n) + 1;

        struct Query {
            int l, r, k;
            long long v;
        };

        int Q = qs.size();
        vector<Query> queries(Q);
        for (int i = 0; i < Q; ++i) {
            queries[i] = {qs[i][0], qs[i][1], qs[i][2], qs[i][3]};
        }

        auto modpow = [&](long long x, long long e) {
            long long r = 1;
            while (e) {
                if (e & 1) r = r * x % MOD;
                x = x * x % MOD;
                e >>= 1;
            }
            return r;
        };

        vector<long long> mul(n, 1);

        for (auto &q : queries) {
            if (q.k > B) {
                for (int i = q.l; i <= q.r; i += q.k) {
                    mul[i] = mul[i] * q.v % MOD;
                }
            }
        }

        vector<vector<int>> g(B + 1);
        for (int i = 0; i < Q; ++i) {
            if (queries[i].k <= B) {
                g[queries[i].k].push_back(i);
            }
        }

        for (int k = 1; k <= B; ++k) {
            if (g[k].empty()) continue;

            for (int r = 0; r < k; ++r) {
                vector<int> pos;
                pos.reserve(n / k + 5);

                for (int i = r; i < n; i += k) pos.push_back(i);

                int m = pos.size();
                if (!m) continue;

                vector<long long> d(m + 1, 1);

                for (int idx : g[k]) {
                    auto &q = queries[idx];

                    if (q.l % k != r) continue;

                    int L = (q.l - r) / k;
                    int R = (q.r - r) / k;

                    if (L < 0) L = 0;
                    if (R >= m) R = m - 1;
                    if (L > R) continue;

                    d[L] = d[L] * q.v % MOD;

                    long long inv = modpow(q.v, MOD - 2);
                    if (R + 1 < m) d[R + 1] = d[R + 1] * inv % MOD;
                }

                long long cur = 1;
                for (int i = 0; i < m; ++i) {
                    cur = cur * d[i] % MOD;
                    mul[pos[i]] = mul[pos[i]] * cur % MOD;
                }
            }
        }

        long long res = 0;
        for (int i = 0; i < n; ++i) {
            long long x = a[i] * mul[i] % MOD;
            res ^= x;
        }

        return (int)res;
    }
};