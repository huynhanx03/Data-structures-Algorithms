/*
 Problem: 242. Valid Anagram
 Language: cpp
 Runtime: 12 ms (7.39%)
 Memory: 7.3 MB (100.00%)
 Tags: Hash Table, String, Sorting
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector <int> d(26, 0);
        
        for (auto c : s) ++d[c-'a'];
        for (auto c : t) --d[c - 'a'];
        
        for (int i = 0; i < 26; ++i) if (d[i] != 0) return 0;
        
        return 1;
    }
};