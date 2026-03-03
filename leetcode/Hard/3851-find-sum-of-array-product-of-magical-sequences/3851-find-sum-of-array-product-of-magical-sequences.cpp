/*
 Problem: 3851. Find Sum of Array Product of Magical Sequences
 Language: cpp
 Runtime: 179 ms (39.67%)
 Memory: 54.8 MB (45.46%)
 Tags: Array, Math, Dynamic Programming, Bit Manipulation, Combinatorics, Bitmask
*/
const int MOD = 1e9 + 7;

class Solution {
    long long C[35][35];
    unordered_map<long long, long long> memo;
    vector<int> nums;
    int m, k, n;

    long long modpow(long long a, int b) {
        long long r = 1;
        a %= MOD;
        while (b) {
            if (b & 1) r = r * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return r;
    }

    long long encode(int pos, int used, int carry, int bits) {
        return ((long long)pos << 40) | ((long long)used << 30) | ((long long)carry << 20) | bits;
    }

    long long dfs(int pos, int used, int carry, int bits) {
        if (used > m) return 0;
        if (pos == n) {
            return (used == m && __builtin_popcount(carry) + bits == k) ? 1 : 0;
        }

        long long key = encode(pos, used, carry, bits);
        if (memo.count(key)) return memo[key];

        long long res = 0;
        long long val = nums[pos] % MOD;
        long long mul = 1;

        for (int f = 0; f <= m - used; ++f) {
            int newCarry = (carry + f) >> 1;
            int newBits = bits + ((carry + f) & 1);
            long long comb = C[m - used][f];
            res = (res + dfs(pos + 1, used + f, newCarry, newBits) * mul % MOD * comb) % MOD;
            mul = mul * val % MOD;
        }

        return memo[key] = res;
    }

public:
    int magicalSum(int m_, int k_, vector<int>& nums_) {
        m = m_; k = k_; nums = nums_; n = nums.size();
        for (int i = 0; i <= 30; ++i) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; ++j)
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }

        memo.clear();
        return (int)(dfs(0, 0, 0, 0) % MOD);
    }
};
