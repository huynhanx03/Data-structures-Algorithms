/*
 Problem: 394. Decode String
 Language: cpp
 Runtime: 3 ms (9.78%)
 Memory: 7.6 MB (100.00%)
 Tags: String, Stack, Recursion
*/
class Solution {
public:
    string decodeString(string s) {
        stack <int> st;
        stack <string> stString;
        string scurrent = "";
        int cnt = 0;

        for (auto& c : s) {
            if ('0' <= c && c <= '9') {
                cnt = cnt * 10 + (c - '0');
            } else if (c == '[') {
                st.push(cnt);
                cnt = 0;

                stString.push(scurrent);
                scurrent = "";
            } else if (c == ']') {
                int k = st.top();
                st.pop();

                string stmp = scurrent;

                scurrent = stString.top();
                stString.pop();

                while (k--) {
                    scurrent += stmp;
                }
            } else
                scurrent += c;
        }

        return scurrent;
    }
};