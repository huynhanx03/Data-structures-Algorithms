/*
 Problem: 387. First Unique Character in a String
 Language: cpp
 Runtime: 8 ms (57.59%)
 Memory: 14.7 MB (72.52%)
 Tags: Hash Table, String, Queue, Counting
*/
class Solution {
public:
    int firstUniqChar(string s) {
        vector <int> cnt(26, 0);
        for (const auto& c : s) ++cnt[c - 'a'];
        for (int i = 0; i < s.size(); ++i) if (cnt[s[i] - 'a'] == 1) return i;
        return -1;
    }
};