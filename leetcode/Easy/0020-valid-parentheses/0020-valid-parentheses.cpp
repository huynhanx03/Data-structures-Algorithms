/*
 Problem: 20. Valid Parentheses
 Language: cpp
 Runtime: 8 ms (1.39%)
 Memory: 6.4 MB (100.00%)
 Tags: String, Stack
*/
class Solution {
public:
    bool isValid(string s) {
        map <char, char> mp {{')', '('}, {']', '['}, {'}', '{'}};

        stack <int> st;
        
        for (auto c : s) {
            if (st.empty()) st.push(c);
            else {
                if (c == ')' || c == ']' || c == '}') {
                    if (st.top() == mp[c]) st.pop();
                    else return 0;
                } else st.push(c);
            }
        }
        
        return st.empty();
            
        
    }
};