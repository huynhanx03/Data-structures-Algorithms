/*
 Problem: 392. Is Subsequence
 Language: cpp
 Runtime: 3 ms (5.42%)
 Memory: 7.8 MB (100.00%)
 Tags: Two Pointers, String, Dynamic Programming
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ps = 0, sz = s.size();

        for (auto& c : t) {
            if (ps < sz && c == s[ps])
                ++ps;
        }

        return ps == sz;
    }
};