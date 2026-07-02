/*
 Problem: 3939. Process String with Special Operations II
 Language: cpp
 Runtime: 25 ms (57.15%)
 Memory: 49.6 MB (11.94%)
 Tags: String, Simulation
*/
class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> len(n);

        long long cur = 0;

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if ('a' <= c && c <= 'z') {
                cur++;
            } else if (c == '*') {
                if (cur > 0) cur--;
            } else if (c == '#') {
                cur *= 2;
            }

            len[i] = cur;
        }

        if (k >= cur) return '.';

        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];

            if (c == '%') {
                k = len[i] - 1 - k;
            } else if (c == '#') {
                k %= (len[i] / 2);
            } else if ('a' <= c && c <= 'z') {
                if (k == len[i] - 1) {
                    return c;
                }
            }
        }

        return '.';
    }
};