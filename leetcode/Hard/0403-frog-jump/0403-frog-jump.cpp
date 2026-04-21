/*
 Problem: 403. Frog Jump
 Language: cpp
 Runtime: 103 ms (47.21%)
 Memory: 47.1 MB (43.81%)
 Tags: Array, Dynamic Programming
*/
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_set<int> st(stones.begin(), stones.end());
        unordered_map<int, unordered_set<int>> dp;

        dp[0].insert(0);

        for (const auto& pos : stones) {
            for (const auto& k : dp[pos]) {
                for (int step = k - 1; step <= k + 1; ++step) {
                    if (step <= 0) continue;
                    int nxt = pos + step;
                    if (st.count(nxt)) {
                        dp[nxt].insert(step);
                    }
                }
            }
        }

        return !dp[stones.back()].empty();
    }
};