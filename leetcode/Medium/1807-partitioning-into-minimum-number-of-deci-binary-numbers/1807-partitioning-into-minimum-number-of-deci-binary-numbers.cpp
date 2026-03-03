/*
 Problem: 1807. Partitioning Into Minimum Number Of Deci-Binary Numbers
 Language: cpp
 Runtime: 4 ms (26.33%)
 Memory: 16.6 MB (56.70%)
 Tags: String, Greedy
*/
class Solution {
public:
    int minPartitions(string n) {
        int ans = -1;
        for (const auto& c : n) ans = max(ans, c - '0');
        return ans;   
    }
};