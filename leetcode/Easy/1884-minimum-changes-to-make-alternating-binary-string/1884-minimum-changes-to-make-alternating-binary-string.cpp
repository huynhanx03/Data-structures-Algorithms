/*
 Problem: 1884. Minimum Changes To Make Alternating Binary String
 Language: cpp
 Runtime: 3 ms (17.69%)
 Memory: 9.6 MB (20.96%)
 Tags: String
*/
class Solution {
public:
    int minOperations(string s) {
        int diff1 = 0, diff2 = 0;

        for (int i = 0; i < s.size(); i++) {
            char expected1 = (i % 2 == 0) ? '0' : '1';
            char expected2 = (i % 2 == 0) ? '1' : '0';

            if (s[i] != expected1) diff1++;
            if (s[i] != expected2) diff2++;
        }

        return min(diff1, diff2);
    }
};