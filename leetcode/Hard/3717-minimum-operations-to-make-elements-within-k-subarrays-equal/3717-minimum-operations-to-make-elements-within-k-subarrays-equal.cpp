/*
 Problem: 3717. Minimum Operations to Make Elements Within K Subarrays Equal
 Language: cpp
 Runtime: 1161 ms (46.88%)
 Memory: 451.8 MB (14.06%)
 Tags: Array, Hash Table, Math, Dynamic Programming, Sliding Window, Heap (Priority Queue)
*/
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> cost(n, 0);

        multiset<int> low, high;
        long long sumLow = 0, sumHigh = 0;

        auto rebalance = [&]() {
            while (low.size() > high.size() + 1) {
                int v = *low.rbegin();
                low.erase(prev(low.end()));
                sumLow -= v;
                high.insert(v);
                sumHigh += v;
            }
            while (low.size() < high.size()) {
                int v = *high.begin();
                high.erase(high.begin());
                sumHigh -= v;
                low.insert(v);
                sumLow += v;
            }
        };

        auto add = [&](int v) {
            if (low.empty() || v <= *low.rbegin()) {
                low.insert(v);
                sumLow += v;
            } else {
                high.insert(v);
                sumHigh += v;
            }
            rebalance();
        };

        auto remove = [&](int v) {
            auto it = low.find(v);
            if (it != low.end()) {
                sumLow -= v;
                low.erase(it);
            } else {
                it = high.find(v);
                sumHigh -= v;
                high.erase(it);
            }
            rebalance();
        };

        for (int i = 0; i < x; i++) add(nums[i]);

        for (int i = 0; i + x <= n; i++) {
            int median = *low.rbegin();
            cost[i] =
                median * (long long)low.size() - sumLow +
                sumHigh - median * (long long)high.size();

            if (i + x < n) {
                remove(nums[i]);
                add(nums[i + x]);
            }
        }

        const long long INF = 1e18;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));
        dp[n][0] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = dp[i + 1][j];
                if (j > 0 && i + x <= n) {
                    dp[i][j] = min(dp[i][j], dp[i + x][j - 1] + cost[i]);
                }
            }
        }

        return dp[0][k];
    }
};
