/*
 Problem: 2554. Minimum Total Distance Traveled
 Language: cpp
 Runtime: 27 ms (65.07%)
 Memory: 13.6 MB (69.18%)
 Tags: Array, Dynamic Programming, Sorting
*/
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int m = factory.size();

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        const long long INF = 1e18;

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, INF));

        for (int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }

        for (int j = 1; j <= m; j++) {
            int pos = factory[j - 1][0];
            int limit = factory[j - 1][1];

            for (int i = 0; i <= n; i++) {
                dp[i][j] = dp[i][j - 1];

                long long cost = 0;

                for (int k = 1; k <= limit && k <= i; k++) {
                    cost += abs(robot[i - k] - pos);
                    if (dp[i - k][j - 1] != INF) {
                        dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + cost);
                    }
                }
            }
        }

        return dp[n][m];
    }
};