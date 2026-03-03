/*
 Problem: 139. Word Break
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 10.2 MB (97.88%)
 Tags: Array, Hash Table, String, Dynamic Programming, Trie, Memoization
*/
class Solution {
public:
    bool wordBreak(string& s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n);

        for (int i = 0; i < n; i++) {
            for (auto& str : wordDict) {
                if (i < str.length() - 1)
                    continue;
                if (i == str.length() - 1 || dp[i - str.length()])
                    if (str == s.substr(i - str.length() + 1, str.length())) {
                        dp[i] = 1;
                        break;
                    }
            }
        }
        return dp[n - 1];
    }
};