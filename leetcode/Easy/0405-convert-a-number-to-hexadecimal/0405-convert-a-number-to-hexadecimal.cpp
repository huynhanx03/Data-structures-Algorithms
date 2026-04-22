/*
 Problem: 405. Convert a Number to Hexadecimal
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 7.8 MB (43.99%)
 Tags: Math, String, Bit Manipulation
*/
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        
        unsigned int x = num;
        string res;
        string hex = "0123456789abcdef";
        
        while (x) {
            res.push_back(hex[x & 15]);
            x >>= 4;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};