/*
 Problem: 1636. Number of Substrings With Only 1s
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 11.5 MB (99.01%)
 Tags: Math, String
*/
class Solution {
public:
    int numSub(string s) {
        long long MOD = 1e9 + 7;
        long long res = 0;
        long long curr = 0;

        for (char c : s) {
            if (c == '1') {
                curr++;
                res = (res + curr) % MOD;
            } else {
                curr = 0;
            }
        }
        return (int)res;
    }
};