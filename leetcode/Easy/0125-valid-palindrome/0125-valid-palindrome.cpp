/*
 Problem: 125. Valid Palindrome
 Language: cpp
 Runtime: 4 ms (16.17%)
 Memory: 7.3 MB (100.00%)
 Tags: Two Pointers, String
*/
class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            while (!isalnum(s[i]) && i < j) ++i;
            while (!isalnum(s[j]) && i < j) --j;
            
            if (tolower(s[i]) != tolower(s[j])) return 0;
        }
        
        return 1;
    }
};