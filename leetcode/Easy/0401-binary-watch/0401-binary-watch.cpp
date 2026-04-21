/*
 Problem: 401. Binary Watch
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 9.7 MB (60.34%)
 Tags: Backtracking, Bit Manipulation
*/
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;

        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    string t = to_string(h) + ":";
                    if (m < 10) t += "0";
                    t += to_string(m);
                    res.push_back(t);
                }
            }
        }

        return res;
    }
};