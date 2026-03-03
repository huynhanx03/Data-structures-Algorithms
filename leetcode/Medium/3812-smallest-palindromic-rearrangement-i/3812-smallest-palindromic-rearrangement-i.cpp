/*
 Problem: 3812. Smallest Palindromic Rearrangement I
 Language: cpp
 Runtime: 51 ms (55.56%)
 Memory: 75.2 MB (38.38%)
 Tags: String, Sorting, Counting Sort
*/
class Solution {
public:
    string smallestPalindrome(string str) {
        vector<int> cnt(26, 0);

        for (const auto& c : str) ++cnt[c - 'a'];

        string s = "";
        char mid = '.';

        for (int i = 0; i < 26; ++i) {
            int count = cnt[i] / 2;
            char c = i + 'a';
            if (cnt[i] % 2) mid = c;

            for (int j = 1; j <= count; ++j) s += c;
        }

        return mid == '.' ? s + string(s.rbegin(), s.rend()) : s + mid + string(s.rbegin(), s.rend());

    }
};