/*
 Problem: 1527. Number of Ways to Paint N × 3 Grid
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 7.8 MB (60.79%)
 Tags: Dynamic Programming
*/
class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;

        long long A = 6; // ABC
        long long B = 6; // ABA

        for (int i = 2; i <= n; i++) {
            long long newA = (2 * A % MOD + 2 * B % MOD) % MOD;
            long long newB = (2 * A % MOD + 3 * B % MOD) % MOD;
            A = newA;
            B = newB;
        }

        return (A + B) % MOD;
    }
};
