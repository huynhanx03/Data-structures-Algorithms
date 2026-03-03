/*
 Problem: 867. New 21 Game
 Language: cpp
 Runtime: 2 ms (75.49%)
 Memory: 12.6 MB (60.67%)
 Tags: Math, Dynamic Programming, Sliding Window, Probability and Statistics
*/
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k - 1 + maxPts) return 1;

        vector <double> dp(n + 1, 0);
        dp[0] = 1;

        double res = 0;
        double sum = 1;

        for (int i = 1; i <= n; ++i) {
            dp[i] = sum / maxPts;
            
            if (i < k) {
                sum += dp[i];
            } else {
                res += dp[i];
            }

            if (i - maxPts >= 0) {
                sum -= dp[i - maxPts];
            }
        }

        return round(res * 1e5) / 1e5;
    }
};