/*
 Problem: 3233. Maximize the Number of Partitions After Operations
 Language: cpp
 Runtime: 557 ms (39.79%)
 Memory: 157.5 MB (50.00%)
 Tags: String, Dynamic Programming, Bit Manipulation, Bitmask
*/
class Solution {
public:
    string s;
    int n, K;
    unordered_map<long long, int> mem;

    int dfs(int i, int mask, int canChange) {
        if (i == n) return 0;
        long long key = ((long long)i << 27) | ((long long)canChange << 26) | mask;
        if (mem.count(key)) return mem[key];
        int res = 0;
        int bit = 1 << (s[i] - 'a');
        int newMask = mask | bit;
        if (__builtin_popcount(newMask) > K) {
            res = 1 + dfs(i + 1, bit, canChange);
        } else {
            res = dfs(i + 1, newMask, canChange);
        }
        if (canChange) {
            for (int c = 0; c < 26; ++c) {
                int nb = 1 << c;
                int nm = mask | nb;
                if (__builtin_popcount(nm) > K) {
                    res = max(res, 1 + dfs(i + 1, nb, 0));
                } else {
                    res = max(res, dfs(i + 1, nm, 0));
                }
            }
        }
        return mem[key] = res;
    }

    int maxPartitionsAfterOperations(string _s, int k) {
        s = _s;
        n = s.size();
        K = k;
        mem.clear();
        int ans = dfs(0, 0, 1) + 1;
        return ans;
    }
};