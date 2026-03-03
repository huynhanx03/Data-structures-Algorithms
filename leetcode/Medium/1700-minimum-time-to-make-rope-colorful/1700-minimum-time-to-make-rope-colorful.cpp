/*
 Problem: 1700. Minimum Time to Make Rope Colorful
 Language: cpp
 Runtime: 3 ms (69.16%)
 Memory: 99.9 MB (34.83%)
 Tags: Array, String, Dynamic Programming, Greedy
*/
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = neededTime[0];
        int ans = 0;
        int n = colors.size();
        for (int i = 1; i < n; ++i) {
            if (colors[i] == colors[i - 1]) {
                ans += min(cost, neededTime[i]);

                if (neededTime[i] > cost) {
                    cost = neededTime[i];
                }
            } else {
                cost = neededTime[i];
            }
        }

        return ans;
    }
};