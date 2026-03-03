/*
 Problem: 3793. Longest Palindrome After Substring Concatenation I
 Language: cpp
 Runtime: 914 ms (50.74%)
 Memory: 216.8 MB (43.28%)
 Tags: Two Pointers, String, Dynamic Programming, Enumeration
*/
class Solution {
private:
    bool isPalindrome(const string& str) {
        int left = 0, right = str.size() - 1;
        while (left < right) {
            if (str[left] != str[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

public:
    int longestPalindrome(string s, string t) {
        int maxLen = 0;
        int n = s.size(), m = t.size();

        for (int i = 0; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                string subS = s.substr(i, j - i);

                for (int k = 0; k <= m; k++) {
                    for (int l = k; l <= m; l++) {
                        string subT = t.substr(k, l - k);
                        string combined = subS + subT;

                        if (isPalindrome(combined)) {
                            maxLen = max(maxLen, (int)combined.size());
                        }
                    }
                }
            }
        }

        return maxLen;
    }
};