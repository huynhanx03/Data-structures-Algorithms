/*
 Problem: 1755. Defuse the Bomb
 Language: cpp
 Runtime: 2 ms (13.25%)
 Memory: 11.8 MB (3.76%)
 Tags: Array, Sliding Window
*/
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        if (k == 0)
            return result;

        vector<int> prefixSum(2 * n + 1, 0);
        for (int i = 0; i < 2 * n; i++)
            prefixSum[i + 1] = prefixSum[i] + code[i % n];

        for (int i = 0; i < n; i++) {
            result[i] = (k > 0) ? prefixSum[i + k + 1] - prefixSum[i + 1]
                                : prefixSum[i + n] - prefixSum[i + n + k];
        }
        return result;
    }
};