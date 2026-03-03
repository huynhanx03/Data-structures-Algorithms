/*
 Problem: 3832. Minimum Cost to Reach Every Position
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 26.7 MB (36.36%)
 Tags: Array
*/
class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int n = cost.size();
        int prev = 1e9;

        vector<int> ans(n, -1);
        
        for (int i = 0; i < n; ++i) {
            prev = min(cost[i], prev);

            ans[i] = prev;
        }

        return ans;
    }
};