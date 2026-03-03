/*
 Problem: 300. Longest Increasing Subsequence
 Language: cpp
 Runtime: 61 ms (61.18%)
 Memory: 13.2 MB (100.00%)
 Tags: Array, Binary Search, Dynamic Programming
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; ++i)
            for (int j = 0; j < i; ++j) {
                if (a[i] > a[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }

        return *max_element(dp.begin(), dp.end());
    }
};