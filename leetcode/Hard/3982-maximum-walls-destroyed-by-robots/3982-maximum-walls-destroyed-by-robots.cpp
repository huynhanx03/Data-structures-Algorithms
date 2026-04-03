/*
 Problem: 3982. Maximum Walls Destroyed by Robots
 Language: cpp
 Runtime: 387 ms (5.33%)
 Memory: 255.3 MB (5.33%)
 Tags: Array, Binary Search, Dynamic Programming, Sorting
*/
class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& d, vector<int>& walls) {
        const int n = robots.size();

        vector<vector<int>> x(n, vector<int>(2));
        for (int i = 0; i < n; ++i) {
            x[i][0] = robots[i];
            x[i][1] = d[i];
        }

        sort(x.begin(), x.end());
        sort(walls.begin(), walls.end());

        x.push_back({(int)1e9, 0});

        auto query = [&](int l, int r) {
            if (l > r) return 0;
            const auto it1 = upper_bound(walls.begin(), walls.end(), r);
            const auto it2 = lower_bound(walls.begin(), walls.end(), l);
            return (int)(it1 - it2);
        };

        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[0][0] = query(x[0][0] - x[0][1], x[0][0]);
        dp[0][1] = query(x[0][0], min(x[1][0] - 1, x[0][0] + x[0][1]));

        for (int i = 1; i < n; ++i) {
            const int pos = x[i][0];
            const int dist = x[i][1];

            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) +
                       query(pos, min(x[i + 1][0] - 1, pos + dist));

            const int leftStart = max(pos - dist, x[i - 1][0] + 1);
            const int leftEnd   = pos;

            dp[i][0] = dp[i - 1][0] + query(leftStart, leftEnd);

            const int overlapStart = leftStart;
            const int overlapEnd   = min(x[i - 1][0] + x[i - 1][1], pos - 1);

            const int val = dp[i - 1][1]
                            + query(leftStart, leftEnd)
                            - query(overlapStart, overlapEnd);

            dp[i][0] = max(dp[i][0], val);
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};