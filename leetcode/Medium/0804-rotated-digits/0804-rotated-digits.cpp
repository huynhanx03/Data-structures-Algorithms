/*
 Problem: 804. Rotated Digits
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.3 MB (38.29%)
 Tags: Math, Dynamic Programming
*/
class Solution {
public:
    int rotatedDigits(int n) {
        string s = to_string(n);
        int m = s.size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(2, vector<int>(2, 0)));
        dp[0][1][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int tight = 0; tight <= 1; ++tight) {
                for (int diff = 0; diff <= 1; ++diff) {
                    int cur = dp[i][tight][diff];
                    if (!cur) continue;

                    int lim = tight ? s[i] - '0' : 9;

                    for (int d = 0; d <= lim; ++d) {
                        if (d == 3 || d == 4 || d == 7) continue;

                        int ntight = tight && d == lim;
                        int ndiff = diff || d == 2 || d == 5 || d == 6 || d == 9;

                        dp[i + 1][ntight][ndiff] += cur;
                    }
                }
            }
        }

        return dp[m][0][1] + dp[m][1][1];
    }
};