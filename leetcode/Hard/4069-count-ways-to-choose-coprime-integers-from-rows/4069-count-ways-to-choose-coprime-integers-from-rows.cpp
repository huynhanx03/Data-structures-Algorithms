/*
 Problem: 4069. Count Ways to Choose Coprime Integers from Rows
 Language: cpp
 Runtime: 191 ms (86.85%)
 Memory: 47.7 MB (65.73%)
 Tags: Array, Math, Dynamic Programming, Matrix, Combinatorics, Number Theory
*/
class Solution {
public:
    const int MOD = 1e9 + 7;
    int countCoprime(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> dp(155, 0);
        
        for (const auto&x :  mat[0])
            dp[x] = (dp[x] + 1) % MOD;

        for (int i = 1; i < n; ++i) {
            vector<int> newdp(155, 0);
            for (const auto&x : mat[i]) {
                for (int v = 1; v <= 150; ++v) {
                    if (dp[v]) {
                        int new_v = gcd(v, x);
                        newdp[new_v] = (newdp[new_v] + dp[v]) % MOD;
                    }
                }
            }
            // for (const auto& x: mat[i]) newdp[x] = (newdp[x] + 1) % MOD;
            dp = newdp;
        }

        return dp[1] % MOD;
    }
};