/*
 Problem: 2089. Maximum Matrix Sum
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 39.2 MB (31.03%)
 Tags: Array, Greedy, Matrix
*/
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sumAbs = 0;
        long long minAbs = LLONG_MAX;
        int negCount = 0;

        for (const auto& row : matrix) {
            for (int x : row) {
                if (x < 0) negCount++;
                long long ax = llabs(x);
                sumAbs += ax;
                minAbs = min(minAbs, ax);
            }
        }

        if (negCount % 2 == 0) {
            return sumAbs;
        }

        return sumAbs - 2 * minAbs;
    }
};
