/*
 Problem: 409. Longest Palindrome
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 9 MB (94.16%)
 Tags: Hash Table, String, Greedy
*/
class Solution {
private:
    int getIndex(char c) {
        if ('a' <= c && c <= 'z') return c - 'a';
        if ('A' <= c && c <= 'Z') return c - 'A' + 26;

        return -1;
    }

public:
    int longestPalindrome(string s) {
        int ans = 0;

        vector<int> cnt(52, 0);

        for (const auto& c : s) {
            ++cnt[getIndex(c)];
        }     

        bool haveOdd = false;

        for (int i = 0; i < 52; ++i) {
            ans += cnt[i] / 2 * 2;

            if (cnt[i] % 2 == 1 && !haveOdd) {
                ++ans;
                haveOdd = true;
            }
        }  

        return ans;
    }
};