/*
 Problem: 1363. Greatest English Letter in Upper and Lower Case
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.9 MB (75.02%)
 Tags: Hash Table, String, Enumeration
*/
class Solution {
public:
    string greatestLetter(string s) {
        int l = 0, u = 0;

        for (const auto& c : s) {
            if (islower(c)) {
                l |= 1 << (c - 'a');
            } else {
                u |= 1 << (c - 'A');
            }
        }

        int mask = l & u;

        for (int i = 25; i >= 0; --i) {
            if (mask & (1 << i)) {
                return string(1, 'A' + i);
            }
        }

        return "";
    }
};