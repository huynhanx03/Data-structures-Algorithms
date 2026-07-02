/*
 Problem: 2248. Minimum Cost of Buying Candies With Discount
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 14.2 MB (52.75%)
 Tags: Array, Greedy, Sorting
*/
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());

        int ans = 0;

        for (int i = 0; i < cost.size(); i++) {
            if (i % 3 != 2) {
                ans += cost[i];
            }
        }

        return ans;
    }
};