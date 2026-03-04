/*
 Problem: 1302. Delete Characters to Make Fancy String
 Language: cpp
 Runtime: 22 ms (72.48%)
 Memory: 44.5 MB (38.23%)
 Tags: String
*/
class Solution {
public:
    string makeFancyString(string s) {
        string res;
        res += s[0];
        int cnt = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) ++cnt;
            else cnt = 1;

            if (cnt < 3) res += s[i];
        }

        return res;
    }
};