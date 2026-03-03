/*
 Problem: 14. Longest Common Prefix
 Language: cpp
 Runtime: 2 ms (11.80%)
 Memory: 11.5 MB (99.59%)
 Tags: Array, String, Trie
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string ans = "";

        string b = strs[0];
        string e = strs[strs.size() - 1];

        for (int i = 0; i < min (b.size(), e.size()); ++i) {
            if (b[i] != e[i])
                return ans;
            
            ans += b[i];
        }

        return ans;
    }
};