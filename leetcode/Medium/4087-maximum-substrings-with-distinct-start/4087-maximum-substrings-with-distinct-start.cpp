/*
 Problem: 4087. Maximum Substrings With Distinct Start
 Language: cpp
 Runtime: 31 ms (47.52%)
 Memory: 25.4 MB (8.45%)
 Tags: Hash Table, String
*/
class Solution {
public:
    int maxDistinct(string s) {
        set<char> st;
        for (const auto& c : s) {
            st.insert(c);
        }

        return st.size();
    }
};