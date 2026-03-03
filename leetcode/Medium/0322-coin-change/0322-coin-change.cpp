/*
 Problem: 322. Coin Change
 Language: cpp
 Runtime: 20 ms (73.43%)
 Memory: 16.4 MB (95.34%)
 Tags: Array, Dynamic Programming, Breadth-First Search
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 5, 1e5);
        
        dp[0] = 0;

        for (auto& coin : coins) {
            if (coin > amount)
                continue;

            dp[coin] = 1;
        }

        for (int i = 1; i <= amount; ++i) {
            for (auto& coin : coins) {
                if ((long)i + coin > (long)amount)
                    continue;

                dp[i + coin] = min(dp[i + coin], dp[i] + 1);
            }
        }

        return dp[amount] == 1e5 ? -1 : dp[amount];
    }
};