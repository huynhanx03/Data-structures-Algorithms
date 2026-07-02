/*
 Problem: 1961. Maximum Ice Cream Bars
 Language: cpp
 Runtime: 37 ms (31.87%)
 Memory: 80.1 MB (99.83%)
 Tags: Array, Greedy, Sorting, Counting Sort
*/
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int ans = 0;
        for (int x : costs) {
            if (coins < x) break;
            coins -= x;
            ++ans;
        }

        return ans;
    }
};