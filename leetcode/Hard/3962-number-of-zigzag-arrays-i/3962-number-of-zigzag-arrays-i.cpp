/*
 Problem: 3962. Number of ZigZag Arrays I
 Language: cpp
 Runtime: 745 ms (29.47%)
 Memory: 649.6 MB (17.44%)
 Tags: Dynamic Programming, Prefix Sum
*/
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;
        int m = r - l + 1;

        if (n == 1) return m;

        vector<long long> u(m + 1), d(m + 1);

        for (int i = 1; i <= m; i++) {
            u[i] = i - 1;
            d[i] = m - i;
        }

        while (--n > 1) {
            vector<long long> nu(m + 1), nd(m + 1);

            long long s = 0;
            for (int i = 1; i <= m; i++) {
                nu[i] = s;
                s = (s + d[i]) % MOD;
            }

            s = 0;
            for (int i = m; i >= 1; i--) {
                nd[i] = s;
                s = (s + u[i]) % MOD;
            }

            u.swap(nu);
            d.swap(nd);
        }

        long long ans = 0;
        for (int i = 1; i <= m; i++) ans = (ans + u[i] + d[i]) % MOD;

        return ans;
    }
};