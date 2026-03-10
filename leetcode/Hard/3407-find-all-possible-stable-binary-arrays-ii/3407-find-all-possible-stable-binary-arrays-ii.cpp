/*
 Problem: 3407. Find All Possible Stable Binary Arrays II
 Language: cpp
 Runtime: 1587 ms (28.77%)
 Memory: 512.7 MB (39.73%)
 Tags: Dynamic Programming, Prefix Sum
*/
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const long long MOD = 1e9 + 7;

        vector dp(zero + 1, vector(one + 1, vector<long long>(2, 0)));

        for (int i = 1; i <= min(zero, limit); ++i)
            dp[i][0][0] = 1;

        for (int j = 1; j <= min(one, limit); ++j)
            dp[0][j][1] = 1;

        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {

                long long v0 = dp[i-1][j][0] + dp[i-1][j][1];
                if (i > limit)
                    v0 = (v0 - dp[i-1-limit][j][1] + MOD) % MOD;
                dp[i][j][0] = v0 % MOD;

                long long v1 = dp[i][j-1][0] + dp[i][j-1][1];
                if (j > limit)
                    v1 = (v1 - dp[i][j-1-limit][0] + MOD) % MOD;
                dp[i][j][1] = v1 % MOD;
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};