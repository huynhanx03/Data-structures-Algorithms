/*
 Problem: 1800. Concatenation of Consecutive Binary Numbers
 Language: cpp
 Runtime: 28 ms (65.46%)
 Memory: 8.2 MB (36.12%)
 Tags: Math, Bit Manipulation, Simulation
*/
class Solution {
public:
    int concatenatedBinary(int n) {
        const long long MOD = 1e9 + 7;
        long long ans = 0;
        long long bits = 0;

        for (long long i = 1; i <= n; ++i) {
            if ((i & (i - 1)) == 0) ++bits;

            ans = ((ans << bits) + i) % MOD;
        }

        return (int) ans;
    }
};