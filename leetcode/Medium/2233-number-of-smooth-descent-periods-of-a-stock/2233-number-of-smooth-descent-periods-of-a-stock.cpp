/*
 Problem: 2233. Number of Smooth Descent Periods of a Stock
 Language: cpp
 Runtime: 7 ms (14.05%)
 Memory: 107 MB (52.74%)
 Tags: Array, Math, Two Pointers, Dynamic Programming, Sliding Window
*/
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long result = 0;
        long long current = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (i > 0 && prices[i] == prices[i - 1] - 1) {
                current++;
            } else {
                current = 1;
            }
            result += current;
        }

        return result;
    }
};
