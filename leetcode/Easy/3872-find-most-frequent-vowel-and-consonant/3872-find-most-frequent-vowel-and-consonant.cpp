/*
 Problem: 3872. Find Most Frequent Vowel and Consonant
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 9.5 MB (60.14%)
 Tags: Hash Table, String, Counting
*/
class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> cnt(26, 0);
        int mx1 = 0, mx2 = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            ++cnt[c - 'a'];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                mx1 = max(mx1, cnt[c - 'a']);
            } else {
                mx2 = max(mx2, cnt[c - 'a']);
            }
        }

        return mx1 + mx2;
    }
};