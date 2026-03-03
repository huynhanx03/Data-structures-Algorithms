/*
 Problem: 2456. Construct Smallest Number From DI String
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.3 MB (30.51%)
 Tags: String, Backtracking, Stack, Greedy
*/
class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();
        string result;
        stack<int> stk;

        for (int i = 0; i <= n; ++i) {
            stk.push(i + 1);
            if (i == n || pattern[i] == 'I') {
                while (!stk.empty()) {
                    result += to_string(stk.top());
                    stk.pop();
                }
            }
        }

        return result;
    }
};