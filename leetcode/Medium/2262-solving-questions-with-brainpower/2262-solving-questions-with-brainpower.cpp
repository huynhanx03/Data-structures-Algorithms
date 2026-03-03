/*
 Problem: 2262. Solving Questions With Brainpower
 Language: cpp
 Runtime: 4 ms (76.65%)
 Memory: 119.8 MB (78.93%)
 Tags: Array, Dynamic Programming
*/
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();

        vector<long long> dp(n, 0);
        dp[n - 1] = questions[n - 1][0];

        for (int i = n - 2; i >= 0; --i) {
            int nextIndex = i + questions[i][1] + 1;
            dp[i] = max(dp[i + 1], questions[i][0] + (nextIndex < n ? dp[nextIndex] : 0));
        }

        return dp[0];
    }
};