/*
 Problem: 402. Remove K Digits
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 11.1 MB (82.55%)
 Tags: String, Stack, Greedy, Monotonic Stack
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;

        for (const auto& c : num) {
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                --k;
            }
            st.push_back(c);
        }

        while (!st.empty() && k > 0) {
            st.pop_back();
            --k;
        }

        int i = 0;
        while (i < st.size() && st[i] == '0') ++i;

        string res = st.substr(i);
        return res.empty() ? "0" : res;
    }
};