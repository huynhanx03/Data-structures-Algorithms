/*
 Problem: 71. Simplify Path
 Language: cpp
 Runtime: 3 ms (66.35%)
 Memory: 11.8 MB (46.49%)
 Tags: String, Stack
*/
class Solution {
public:
    string simplifyPath(string path) {
        stack <string> st;
        int n = path.size();

        for (int i = 0; i < n; ++i) {
            if (path[i] == '/') continue;

            string tmp = "";

            while (i < n && path[i] != '/')
                tmp += path[i++];

            if (tmp == "..") {
                if (!st.empty()) st.pop();
            } else if (tmp != ".")
                st.push(tmp);
        }

        string res = "";

        while (!st.empty()) {
            res = '/' + st.top() + res;
            st.pop();
        }

        if (!res.size())
            res = "/";

        return res;
    }
};