/*
 Problem: 3807. Find Maximum Value in a Constrained Sequence
 Language: cpp
 Runtime: 8 ms (90.29%)
 Memory: 283.2 MB (93.91%)
 Tags: Array, Greedy
*/
class Solution {

public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int> h(n, 2e9);

        h[0] = 0;

        for (const auto& x : restrictions) h[x[0]] = x[1];
        for (int i = 1; i < n; ++i) {
            h[i] = min(h[i], h[i - 1] + diff[i - 1]);
        }

        int ans = h[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            h[i] = min(h[i], h[i + 1] + diff[i]);
            ans = max(ans, h[i]);
        }

        return ans;
    }
};