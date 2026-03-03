/*
 Problem: 1476. Count Negative Numbers in a Sorted Matrix
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 14 MB (91.43%)
 Tags: Array, Binary Search, Matrix
*/
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        for (const auto& g: grid) {
            for (const auto& v: g) {
                cnt += v < 0;
            }
        }

        return cnt;
    }
};