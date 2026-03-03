/*
 Problem: 22. Generate Parentheses
 Language: cpp
 Runtime: 6 ms (13.90%)
 Memory: 20.6 MB (7.68%)
 Tags: String, Dynamic Programming, Backtracking
*/
class Solution {
public:
    vector<string> ans;

    void generate(string s, int cnt, int& n) {
        if (s.size() == n * 2) {
            if (cnt == 0) ans.push_back(s);
            return;
        }

        if (cnt > 0)
            generate(s + ')', cnt - 1, n);
        
        generate(s + '(', cnt + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        generate("(", 1, n);

        return ans;
    }
};