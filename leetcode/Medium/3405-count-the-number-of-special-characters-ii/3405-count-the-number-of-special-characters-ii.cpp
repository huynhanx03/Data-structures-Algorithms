/*
 Problem: 3405. Count the Number of Special Characters II
 Language: cpp
 Runtime: 84 ms (24.83%)
 Memory: 24.2 MB (86.21%)
 Tags: Hash Table, String
*/
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        vector<bool> lower(26, false), upper(26, false);

        for (const auto& c : word) {
            if (islower(c)) {
                lower[c - 'a'] = !upper[c - 'a'];
            } else {
                upper[c - 'A'] = true;
            }
        }

        for (int i = 0; i < 26; ++i)
            ans += lower[i] && upper[i];

        return ans;
    }
};