/*
 Problem: 2598. Shortest Distance to Target String in a Circular Array
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 18.4 MB (37.22%)
 Tags: Array, String
*/
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int res = n + 1;

        for (int i = 0; i < n; ++i) {
            if (words[i] == target) {
                int diff = abs(i - startIndex);
                int dist = min(diff, n - diff);
                res = min(res, dist);
            }
        }

        return res == n + 1 ? -1 : res;
    }
};