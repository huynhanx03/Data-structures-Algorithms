/*
 Problem: 2059. Unique Length-3 Palindromic Subsequences
 Language: cpp
 Runtime: 19 ms (94.98%)
 Memory: 14 MB (86.78%)
 Tags: Hash Table, String, Bit Manipulation, Prefix Sum
*/
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1), last(26, -1);
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            int c = s[i]-'a';
            if(first[c] == -1) first[c] = i;
            last[c] = i;
        }

        int ans = 0;
        for(int c = 0; c < 26; ++c) {
            if(first[c] == last[c]) continue;
            bool seen[26] = {false};
            for(int i = first[c]+1; i < last[c]; ++i)
                seen[s[i]-'a'] = true;
            for(int k = 0; k < 26; ++k)
                if(seen[k]) ans++;
        }
        return ans;
    }
};