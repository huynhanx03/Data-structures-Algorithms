/*
 Problem: 205. Isomorphic Strings
 Language: cpp
 Runtime: 12 ms (6.72%)
 Memory: 9.5 MB (27.66%)
 Tags: Hash Table, String
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int nS = s.size();
        int nT = s.size();

        if (nS != nT)
            return false;

        map<char, int> pS;
        map<char, int> pT;

        for (int i = 0; i < nS; ++i) {
            if (pS[s[i]] != pT[t[i]])
                return false;

            pS[s[i]] = i + 1;
            pT[t[i]] = i + 1;
        }

        return true;
    }
};