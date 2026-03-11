/*
 Problem: 1054. Complement of Base 10 Integer
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 7.8 MB (59.24%)
 Tags: Bit Manipulation
*/
class Solution {
public:
    int bitwiseComplement(int n) {
        int mask = 1;
        
        while (mask < n) {
            mask = (mask << 1) | 1;
        }
        
        return n ^ mask;
    }
};