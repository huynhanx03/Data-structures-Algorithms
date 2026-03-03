/*
 Problem: 8. String to Integer (atoi)
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 9.1 MB (80.79%)
 Tags: String
*/
class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        
        // Step 1: Ignore leading whitespace
        while (i < n && s[i] == ' ') ++i;
        
        // Step 2: Determine sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            ++i;
        }
        
        // Step 3: Convert digits to integer
        long long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            if (result * sign >= INT_MAX) {
                return INT_MAX;
            }
            if (result * sign <= INT_MIN) {
                return INT_MIN;
            }
            ++i;
        }
        
        return result * sign;
    }
};