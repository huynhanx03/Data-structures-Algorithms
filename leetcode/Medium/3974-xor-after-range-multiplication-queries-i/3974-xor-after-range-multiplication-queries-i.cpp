/*
 Problem: 3974. XOR After Range Multiplication Queries I
 Language: cpp
 Runtime: 194 ms (5.26%)
 Memory: 279.9 MB (5.26%)
 Tags: Array, Divide and Conquer, Simulation
*/
class Solution {
public:
    int xorAfterQueries(vector<int>& a, vector<vector<int>>& qs) {
        const int MOD = 1e9 + 7;
        int n = a.size();
        int B = sqrt(n) + 1;

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

        for (auto &q : qs) {
            int l = q[0], r = q[1], k = q[2];
            long long v = q[3];
            if (k > B) {
                for (int i = l; i <= r; i += k) {
                    mul[i] = mul[i] * v % MOD;
                }
            }
        }

        vector<vector<vector<int>>> g(B + 1);
        for (auto &q : qs) {
            if (q[2] <= B) g[q[2]].push_back(q);
        }

        for (int k = 1; k <= B; ++k) {
            if (g[k].empty()) continue;

            for (int r = 0; r < k; ++r) {
                vector<int> pos;
                for (int i = r; i < n; i += k) pos.push_back(i);

                int m = pos.size();
                if (!m) continue;

                vector<long long> d(m + 1, 1);

                for (auto &q : g[k]) {
                    int l = q[0], rr = q[1];
                    long long v = q[3];

                    if (l % k != r) continue;

                    int L = (l - r) / k;
                    int R = (rr - r) / k;

                    if (L < 0) L = 0;
                    if (R >= m) R = m - 1;
                    if (L > R) continue;

                    d[L] = d[L] * v % MOD;

                    long long inv = modpow(v, MOD - 2);
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