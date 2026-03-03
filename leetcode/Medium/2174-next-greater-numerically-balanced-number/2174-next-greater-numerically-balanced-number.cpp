/*
 Problem: 2174. Next Greater Numerically Balanced Number
 Language: cpp
 Runtime: 881 ms (10.87%)
 Memory: 257.2 MB (8.64%)
 Tags: Hash Table, Math, Backtracking, Counting, Enumeration
*/
class Solution {
public:
    bool isBalanced(int x) {
        string s = to_string(x);
        vector<int> count(10, 0);

        for (char c : s) {
            count[c - '0']++;
        }

        for (char c : s) {
            int digit = c - '0';
            if (count[digit] != digit) {
                return false;
            }
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        n++;
        while (true) {
            if (isBalanced(n)) return n;
            n++;
        }
    }
};