/*
 Problem: 3383. Taking Maximum Energy From the Mystic Dungeon
 Language: cpp
 Runtime: 138 ms (86.87%)
 Memory: 151.8 MB (100.00%)
 Tags: Array, Prefix Sum
*/
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            if (i < k) dp[i] = energy[i];
            else dp[i] = max(energy[i], dp[i - k] + energy[i]);
        }

        int ans = -1000;

        for (int i = n - k; i < n; ++i) {
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};