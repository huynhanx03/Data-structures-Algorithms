/*
 Problem: 3001. Apply Operations to Maximize Score
 Language: cpp
 Runtime: 254 ms (70.12%)
 Memory: 270.8 MB (27.59%)
 Tags: Array, Math, Stack, Greedy, Sorting, Monotonic Stack, Number Theory
*/
class Solution {
private:
    const int MOD = 1000000007;

    long long modPow(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp) {
            if (exp & 1)
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        
        vector<int> spf(mx+1);
        iota(spf.begin(), spf.end(), 0);
        
        for (int i = 2; i * i <= mx; ++i) 
            if (spf[i] == i) 
                for (int j = i * i; j <= mx; j += i)
                    if (spf[j] == j) spf[j] = i;

        auto getPrimeScore = [&](int x) -> int {
            int cnt = 0, prev = -1;
            while (x > 1) {
                int p = spf[x];
                if (p != prev) { cnt++; prev = p; }
                x /= p;
            }
            return cnt;
        };

        vector<int> ps(n);
        for (int i = 0; i < n; ++i)
            ps[i] = getPrimeScore(nums[i]);

        vector<int> dpL(n, 1), dpR(n, 1);
        for (int i = 1; i < n; ++i) {
            int j = i - 1;
            while (j >= 0 && ps[j] < ps[i]) 
                j -= dpL[j];
            dpL[i] = i - j;
        }
        for (int i = n - 2; i >= 0; --i) {
            int j = i + 1;
            while (j < n && ps[j] <= ps[i]) 
                j += dpR[j];
            dpR[i] = j - i;
        }

        vector<pair<int, long long>> arr;
        for (int i = 0; i < n; ++i) {
            long long cnt = (long long) dpL[i] * dpR[i];
            arr.push_back({nums[i], cnt});
        }

        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a.first > b.first || (a.first == b.first && a.second > b.second);
        });

        long long ans = 1;
        for (auto &p : arr) {
            if (k <= 0) break;
            long long use = min((long long) k, p.second);
            k -= use;
            ans = (ans * modPow(p.first, use)) % MOD;
        }
        return ans;
    }
};