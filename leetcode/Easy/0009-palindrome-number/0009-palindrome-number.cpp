/*
 Problem: 9. Palindrome Number
 Language: cpp
 Runtime: 4 ms (31.68%)
 Memory: 8.5 MB (65.42%)
 Tags: Math
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return 0;
        
        long tmp = x;
        long reversed = 0;

        while (tmp != 0) {
            int digit = tmp % 10;
            reversed = reversed * 10 + digit;
            tmp /= 10; 
        }

        return reversed == x;
    }
};