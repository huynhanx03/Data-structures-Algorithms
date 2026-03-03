/*
 Problem: 3351. Maximize Happiness of Selected Children
 Language: cpp
 Runtime: 155 ms (59.71%)
 Memory: 107.7 MB (98.50%)
 Tags: Array, Greedy, Sorting
*/
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long result = 0;

        for (int i = 0; i < k; ++i) {
            int current = happiness[i] - i;
            if (current <= 0) break;
            result += current;
        }

        return result;
    }
};
