/*
 Problem: 1833. Find the Highest Altitude
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 10.8 MB (41.64%)
 Tags: Array, Prefix Sum
*/
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0, s = 0;

        for (const auto& x : gain) {
            s += x;
            res = max(res, s);
        }

        return res;
    }
};