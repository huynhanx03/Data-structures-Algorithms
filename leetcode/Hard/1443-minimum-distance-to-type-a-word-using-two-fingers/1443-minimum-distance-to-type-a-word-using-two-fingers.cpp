/*
 Problem: 1443. Minimum Distance to Type a Word Using Two Fingers
 Language: cpp
 Runtime: 3 ms (89.56%)
 Memory: 9.8 MB (63.86%)
 Tags: String, Dynamic Programming
*/
class Solution {
public:
    int minimumDistance(string word) {
        const int INF = 1e9;
        vector<int> dp(26, 0);

        auto dist = [&](int a, int b) {
            int x1 = a / 6, y1 = a % 6;
            int x2 = b / 6, y2 = b % 6;
            return abs(x1 - x2) + abs(y1 - y2);
        };

        for (int i = 1; i < word.size(); ++i) {
            vector<int> ndp(26, INF);
            int p = word[i - 1] - 'A';
            int c = word[i] - 'A';

            for (int j = 0; j < 26; ++j) {
                ndp[j] = min(ndp[j], dp[j] + dist(p, c));
                ndp[p] = min(ndp[p], dp[j] + dist(j, c));
            }

            dp = move(ndp);
        }

        return *min_element(dp.begin(), dp.end());
    }
};