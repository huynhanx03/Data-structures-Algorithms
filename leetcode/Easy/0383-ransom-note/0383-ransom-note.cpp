/*
 Problem: 383. Ransom Note
 Language: cpp
 Runtime: 14 ms (5.05%)
 Memory: 10.2 MB (99.98%)
 Tags: Hash Table, String, Counting
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector <int> cnt(30, 0);

        for (auto& c : magazine) {
            ++cnt[c - 'a'];
        }

        for (auto& c : ransomNote) {
            if (--cnt[c - 'a'] < 0)
                return 0;
        }

        return 1;
    }
};