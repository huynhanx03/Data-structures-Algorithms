/*
 Problem: 4136. Concatenate Non-Zero Digits and Multiply by Sum II
 Language: cpp
 Runtime: 45 ms (56.06%)
 Memory: 162.5 MB (34.93%)
 Tags: Math, String, Prefix Sum
*/
class Solution {
private:
    long long MOD = 1e9 + 7;
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> cnt(n + 1, 0), sum(n + 1, 0), h(n + 1, 0), pow10(n + 1, 1);

        for (int i = 1; i <= n; ++i) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        for (int i = 1; i <= n; ++i) {
            int v = s[i - 1] - '0';

            if (v == 0) {
                cnt[i] = cnt[i - 1];
                sum[i] = sum[i - 1];
                h[i] = h[i - 1];
            } else {
                cnt[i] = cnt[i - 1] + 1;
                sum[i] = sum[i - 1] + v;
                h[i] = (h[i - 1] * 10 + v) % MOD;
            }
        }

        vector<int> ans;
        for (const auto& q : queries) {
            int l = q[0] + 1, r = q[1] + 1;
            long long sizeDigit = cnt[r] - cnt[l - 1];
            long long sumDigit = (sum[r] - sum[l - 1] + MOD) % MOD;
            long long right = h[r], left = h[l - 1];

            long long x = (right - left * pow10[sizeDigit] % MOD + MOD) % MOD;
            long long mul = x * sumDigit % MOD;
        
            ans.push_back((int) mul);
        }

        return ans;
    }
};