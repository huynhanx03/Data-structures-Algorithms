/*
 Problem: 121. Best Time to Buy and Sell Stock
 Language: cpp
 Runtime: 259 ms (6.17%)
 Memory: 93.3 MB (99.99%)
 Tags: Array, Dynamic Programming
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        
        int p = prices[0];
        
        for (auto x : prices) {
            if (p < x)
                ans = max(ans, x - p);
            else p = x;
        }
        
        return ans;
    }
};