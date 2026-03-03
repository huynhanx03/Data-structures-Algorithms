/*
 Problem: 3786. Longest Palindromic Subsequence After at Most K Operations
 Language: cpp
 Runtime: 378 ms (97.08%)
 Memory: 240.3 MB (62.77%)
 Tags: String, Dynamic Programming
*/
class Solution {
public:
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, 0)));

        // Base case: Single characters are palindromes of length 1
        for (int i = 0; i < n; ++i) {
            for (int l = 0; l <= k; ++l) {
                dp[i][i][l] = 1;
            }
        }

        // Fill the DP table
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                for (int l = 0; l <= k; ++l) {
                    if (s[i] == s[j]) {
                        dp[i][j][l] = dp[i + 1][j - 1][l] + 2;
                    } else {
                        dp[i][j][l] = max(dp[i + 1][j][l], dp[i][j - 1][l]);
                        int dis = min(abs(s[i] - s[j]), 26 - abs(s[i] - s[j]));
                        if (l >= dis) {
                            dp[i][j][l] = max(dp[i][j][l], dp[i + 1][j - 1][l - dis] + 2);
                        }
                    }
                }
            }
        }

        return dp[0][n - 1][k];
    }
};
