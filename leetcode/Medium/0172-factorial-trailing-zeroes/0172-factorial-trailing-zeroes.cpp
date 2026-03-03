/*
 Problem: 172. Factorial Trailing Zeroes
 Language: cpp
 Runtime: 7 ms (2.73%)
 Memory: 8 MB (99.52%)
 Tags: Math
*/
class Solution {
public:
    int trailingZeroes(int n) {
        vector <int> cnt(10, 0);

        for (int i = 1; i <= n; ++i) {
            int x = i;

            while (x % 2 == 0) {
                x /= 2;
                ++cnt[2];
            }

            while (x % 5 == 0) {
                x /= 5;
                ++cnt[5];
            }
        }

        return min(cnt[2], cnt[5]);
    }
};