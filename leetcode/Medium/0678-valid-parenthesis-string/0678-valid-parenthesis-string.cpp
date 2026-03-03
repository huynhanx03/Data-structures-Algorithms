/*
 Problem: 678. Valid Parenthesis String
 Language: cpp
 Runtime: 3 ms (9.16%)
 Memory: 7.4 MB (100.00%)
 Tags: String, Dynamic Programming, Stack, Greedy
*/
class Solution {
public:
    bool checkValidString(string s) {
        int p1 = 0;
        int p2 = 0;

        for (auto& c : s) {
            if (c == '(')
            {
                ++p1;
                ++p2;
            }
            else if (c == '*')
                {
                    ++p1;
                    --p2;
                }
            else {
                --p1;
                --p2;
            }

            if (p1 < 0)
                return false;

            if (p2 < 0)
                p2 = 0;
        }

        return p2 == 0;
    }
};