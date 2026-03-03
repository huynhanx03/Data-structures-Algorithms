/*
 Problem: 4153. Count Routes to Climb a Rectangular Grid
 Language: cpp
 Runtime: 291 ms (37.05%)
 Memory: 326.1 MB (30.35%)
 Tags: Array, Dynamic Programming, Matrix, Prefix Sum
*/
class Solution {
private:
    const long long MOD = 1e9 + 7;

    vector <int> getRangeSums(const vector<int>& a, int k) {
        int n = a.size();
        if (n == 0) return {};
        vector <long long> p(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            p[i + 1] = (p[i] + a[i]) % MOD;
        }

        vector <int> res(n);

        for (int i = 0; i < n; ++i) {
            int l = max(0, i - k);
            int r = min(i + k, n - 1);

            res[i] = (p[r + 1] - p[l] + MOD) % MOD;
        }

        return res;
    }
public:
    int numberOfRoutes(vector<string>& grid, int d) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> dp(m, 0);
        for (int j = 0; j < m; ++j) {
            if (grid[n - 1][j] == '.') dp[j] = 1;
        }

        long long d2 = 1LL * d * d - 1;
        int l = (d >= 1) ? (int) sqrt(d2) : -1;
        if (l < 0) return 0;

        for (int r = n - 1; r > 0; --r) {
            vector <int> tmp = getRangeSums(dp, d);
            vector <int> s(m);

            for (int j = 0; j < m; ++j) {
                s[j] = (grid[r][j] == '.') ? tmp[j] : 0;
            }

            vector<int> jump = getRangeSums(s, l);
            for (int i = 0; i < m; ++i) {
                dp[i] = (grid[r - 1][i] == '.') ? jump[i] : 0;
            }
        }

        vector<int> f = getRangeSums(dp, d);
        long long ans = 0;
        for (int j = 0; j < m; ++j) {
            if (grid[0][j] == '.') ans = (ans + f[j]) % MOD;
        }
        
        return (int) ans;
    }
};