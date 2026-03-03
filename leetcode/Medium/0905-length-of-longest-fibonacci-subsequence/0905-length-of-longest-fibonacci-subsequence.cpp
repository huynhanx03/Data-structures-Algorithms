/*
 Problem: 905. Length of Longest Fibonacci Subsequence
 Language: cpp
 Runtime: 315 ms (48.28%)
 Memory: 149.8 MB (46.55%)
 Tags: Array, Hash Table, Dynamic Programming
*/
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;
        
        unordered_map<int, int> index;
        for (int i = 0; i < n; ++i) {
            index[arr[i]] = i;
        }
        
        int maxLength = 0;
        vector<vector<int>> dp(n, vector<int>(n, 2));
        
        for (int k = 2; k < n; ++k) {
            for (int j = k - 1; j > 0; --j) {
                int i = index.find(arr[k] - arr[j]) != index.end() ? index[arr[k] - arr[j]] : -1;
                if (i >= 0 && i < j) {
                    dp[j][k] = dp[i][j] + 1;
                    maxLength = max(maxLength, dp[j][k]);
                }
            }
        }
        
        return maxLength >= 3 ? maxLength : 0;
    }
};
