/*
 Problem: 2017. Minimum Number of Flips to Make the Binary String Alternating
 Language: cpp
 Runtime: 20 ms (55.20%)
 Memory: 17.3 MB (61.60%)
 Tags: String, Dynamic Programming, Sliding Window
*/
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string ss = s + s;

        int diff1 = 0, diff2 = 0;
        int res = INT_MAX;

        for (int i = 0; i < ss.size(); i++) {

            char p1 = (i % 2 == 0) ? '0' : '1';
            char p2 = (i % 2 == 0) ? '1' : '0';

            if (ss[i] != p1) diff1++;
            if (ss[i] != p2) diff2++;

            if (i >= n) {
                char old = ss[i - n];

                char op1 = ((i - n) % 2 == 0) ? '0' : '1';
                char op2 = ((i - n) % 2 == 0) ? '1' : '0';

                if (old != op1) diff1--;
                if (old != op2) diff2--;
            }

            if (i >= n - 1) {
                res = min(res, min(diff1, diff2));
            }
        }

        return res;
    }
};