/*
 Problem: 2050. Count Good Numbers
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 7.9 MB (68.87%)
 Tags: Math, Recursion
*/
class Solution {
private:
    const long MOD = 1e9 + 7;

    long long powm(long long base, long long expo) {
        if (expo == 0)
            return 1;

        long long newexpo = expo / 2;
        long long v = powm(base, newexpo);
        long long ans = v * v % MOD;
        if (expo & 1) ans = (ans * base) % MOD;

        return ans;
    }

public:
    int countGoodNumbers(long long n) {
        if (n == 1) return 5;
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return powm(5, even) * powm(4, odd) % MOD;
    }
};