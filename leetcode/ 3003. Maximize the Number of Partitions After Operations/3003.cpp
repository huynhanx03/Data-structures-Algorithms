class Solution {
public:
    string s;
    int n, K;
    unordered_map<long long, int> mem;

    int dfs(int i, int mask, bool canChange) {
        if (i == n) return 0;
        long long key = ((long long)i << 27) | ((long long)canChange << 26) | mask;
        if (mem.count(key)) return mem[key];

        int bit = 1 << (s[i] - 'a');
        int newMask = mask | bit;
        int res;

        if (__builtin_popcount(newMask) > K)
            res = 1 + dfs(i + 1, bit, canChange);
        else
            res = dfs(i + 1, newMask, canChange);

        if (canChange) {
            for (int c = 0; c < 26; ++c) {
                int nb = 1 << c;
                int nm = mask | nb;
                if (__builtin_popcount(nm) > K)
                    res = max(res, 1 + dfs(i + 1, nb, 0));
                else
                    res = max(res, dfs(i + 1, nm, 0));
            }
        }

        return mem[key] = res;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        this->s = s;
        n = s.size();
        K = k;
        mem.clear();
        return dfs(0, 0, 1) + 1;
    }
};