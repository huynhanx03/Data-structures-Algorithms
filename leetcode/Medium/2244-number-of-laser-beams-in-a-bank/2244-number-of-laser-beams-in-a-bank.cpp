/*
 Problem: 2244. Number of Laser Beams in a Bank
 Language: cpp
 Runtime: 19 ms (6.83%)
 Memory: 27.3 MB (80.42%)
 Tags: Array, Math, String, Matrix
*/
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int pre = -1;
        int ans = 0;
        for (const auto&s : bank) {
            int c = count(s.begin(), s.end(), '1');

            if (pre != -1) {
                ans += c * pre;
            }

            if (c > 0) pre = c;
        }

        return ans;
    }
};