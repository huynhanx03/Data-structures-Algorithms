/*
 Problem: 4054. Count Distinct Integers After Removing Zeros
 Language: cpp
 Runtime: 12 ms (7.51%)
 Memory: 14.8 MB (5.27%)
 Tags: Math, Dynamic Programming
*/
class Solution {
public:
    long long countDistinct(long long n) {
        string s = to_string(n);
        int L = s.size();

        vector<vector<long long>> dp(20, vector<long long>(2, 0));
        vector<vector<bool>> vis(20, vector<bool>(2, 0));

        function<long long(int, int)> dfs = [&](int pos, int tight) -> long long{
            if (pos == L) return 1LL;

            if (vis[pos][tight]) return dp[pos][tight];
            vis[pos][tight] = true;

            long long res = 0;
            int limit = tight ? (s[pos] - '0') : 9;

            for (int d = 1; d <= limit; ++d) {
                int nt = tight && (d == limit);
                res += dfs(pos + 1, nt);
            }

            dp[pos][tight] = res;
            return res;
        };

        long long sameLen = dfs(0, 1);
        long long shorter = 0, p = 9;
        for (int i = 1; i < L; ++i) {
            shorter += p;
            p *= 9;
        }

        return sameLen + shorter;
    }
};