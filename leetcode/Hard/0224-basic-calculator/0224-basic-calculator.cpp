/*
 Problem: 224. Basic Calculator
 Language: cpp
 Runtime: 16 ms (13.71%)
 Memory: 285.9 MB (5.01%)
 Tags: Math, String, Stack, Recursion
*/
class Solution {
public:
    int idx;

    int calculate(string s) {
        idx = 0;
        return cal(s, s.size());
    }

    int cal(string s, int sz) {
        int num = 0, res = 0, sign = 1;

        while (idx < sz) {
            char c = s[idx++];

            if (c == ' ')
                continue;
            else if (c >= '0' && c <= '9')
                num = num * 10 + (c - '0');
            else if (c == '+' || c == '-') {
                res += num * sign;
                num = 0;
                sign = c == '+' ? 1 : -1;
            } else if (c == '(') {
                num = cal(s, sz);
            } else if (c == ')') {
                return res + num * sign;
            }
        }

        return res + num * sign;
    }
};