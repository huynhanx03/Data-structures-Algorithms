/*
 Problem: 122. Best Time to Buy and Sell Stock II
 Language: cpp
 Runtime: 6 ms (25.88%)
 Memory: 15.7 MB (100.00%)
 Tags: Array, Dynamic Programming, Greedy
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for (int i = 1; i < prices.size(); ++i)
            profit += max(0, prices[i] - prices[i - 1]);

        return profit;
    }
};