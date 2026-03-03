/*
 Problem: 3864. Count the Number of Computer Unlocking Permutations
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 92.9 MB (37.53%)
 Tags: Array, Math, Brainteaser, Combinatorics
*/
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const long long MOD = 1e9 + 7;
        int n = complexity.size();
        int first = complexity[0];

        for (int i = 1; i < n; ++i) {
            if (complexity[i] <= first) return 0;
        }

        long long res = 1;
        for (int i = 2; i < n; ++i) {
            res = (res * i) % MOD;
        }

        return (int) res;
    }
};