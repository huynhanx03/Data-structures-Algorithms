/*
 Problem: 1737. Maximum Nesting Depth of the Parentheses
 Language: cpp
 Runtime: 3 ms (1.45%)
 Memory: 7.4 MB (100.00%)
 Tags: String, Stack
*/
class Solution {
public:
    int maxDepth(string s) {
        int len = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                len++;
                ans = max(len, ans);
            }
            else if (s[i] == ')')
                --len;
        }

        return ans;
    }
};