/*
 Problem: 2408. Number of People Aware of a Secret
 Language: cpp
 Runtime: 9 ms (25.76%)
 Memory: 9.3 MB (73.36%)
 Tags: Dynamic Programming, Queue, Simulation
*/
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n);
        dp[0] = 1;

        const int MOD = 1e9 + 7;


        for (int i = 0; i < n; ++i) {
            for (int j = i + delay; j < i + forget && j < n; ++j) {
                dp[j] = (int) ((dp[i] * 1LL + dp[j]) % MOD);
            }
        }

        int sum = 0;

        for (int i = n - forget; i < n; ++i)
            sum = (sum + dp[i]) % MOD;

        return sum;
    }
};