/*
 Problem: 58. Length of Last Word
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 7.5 MB (100.00%)
 Tags: String
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;

        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                if (len > 0)
                    return len;
            }

            else
                ++len;
        }

        return len;
    }
};