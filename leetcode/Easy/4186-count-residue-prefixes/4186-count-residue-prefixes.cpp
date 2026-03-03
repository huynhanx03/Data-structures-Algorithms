/*
 Problem: 4186. Count Residue Prefixes
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 10 MB (51.57%)
 Tags: Hash Table, String
*/
class Solution {
public:
    int residuePrefixes(string s) {
        int cnt = 0;
        set<char> st;

        for (int i = 0; i < s.size(); ++i) {
            st.insert(s[i]);
            int len = i + 1;
            if (st.size() == len % 3) ++cnt;
        }
        
        return cnt;
    }
};