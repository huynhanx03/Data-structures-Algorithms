/*
 Problem: 3980. Best Time to Buy and Sell Stock using Strategy
 Language: cpp
 Runtime: 42 ms (5.46%)
 Memory: 352 MB (5.46%)
 Tags: Array, Sliding Window, Prefix Sum
*/
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long base = 0;

        vector<long long> A(n), B(n);
        for (int i = 0; i < n; i++) {
            A[i] = 1LL * strategy[i] * prices[i];
            B[i] = 1LL * (1 - strategy[i]) * prices[i];
            base += A[i];
        }

        vector<long long> preA(n + 1, 0), preB(n + 1, 0);
        for (int i = 0; i < n; i++) {
            preA[i + 1] = preA[i] + A[i];
            preB[i + 1] = preB[i] + B[i];
        }

        long long bestDelta = 0;
        int half = k / 2;

        for (int l = 0; l + k <= n; l++) {
            long long removeBuy =
                preA[l + half] - preA[l];

            long long addSell =
                preB[l + k] - preB[l + half];

            long long delta = -removeBuy + addSell;
            bestDelta = max(bestDelta, delta);
        }

        return base + bestDelta;
    }
};
