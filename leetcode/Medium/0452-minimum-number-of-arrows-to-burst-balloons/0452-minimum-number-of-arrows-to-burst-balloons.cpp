/*
 Problem: 452. Minimum Number of Arrows to Burst Balloons
 Language: cpp
 Runtime: 109 ms (9.45%)
 Memory: 106.5 MB (11.31%)
 Tags: Array, Greedy, Sorting
*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(), p.end());
        int lastpoint = p[0][1];
        int ans = 1;
        for(auto point : p) {
            if(point[0] > lastpoint) {
                ans++;
                lastpoint = point[1];
            }
            lastpoint = min(point[1],lastpoint);
        }
        return ans;
    }
};