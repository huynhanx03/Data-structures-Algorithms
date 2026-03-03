/*
 Problem: 4168. Mirror Distance of an Integer
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.5 MB (87.07%)
 Tags: Math
*/
class Solution {
public:
    int mirrorDistance(int n) {
        int x = n;
        int rev = 0;

        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        return abs(rev - n);
    }
};