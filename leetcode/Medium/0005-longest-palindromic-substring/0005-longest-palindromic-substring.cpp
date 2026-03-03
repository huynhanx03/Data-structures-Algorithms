/*
 Problem: 5. Longest Palindromic Substring
 Language: cpp
 Runtime: 7 ms (86.59%)
 Memory: 9.5 MB (55.80%)
 Tags: Two Pointers, String, Dynamic Programming
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int n = s.size();
        int start = 0, maxLength = 1;

        for (int i = 0; i < n; ++i) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);

            int len = max(len1, len2);
            if (len > maxLength) {
                start = i - (len - 1) / 2;
                maxLength = len;
            }
        }

        return s.substr(start, maxLength);
    }
private:
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return right - left - 1;
    }
};