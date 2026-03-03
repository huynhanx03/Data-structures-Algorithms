/*
 Problem: 190. Reverse Bits
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 7.6 MB (100.00%)
 Tags: Divide and Conquer, Bit Manipulation
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            result <<= 1;          // Shift the result to the left by 1 bit
            result |= (n & 1);     // Add the least significant bit of n to the result
            n >>= 1;               // Shift n to the right by 1 bit
        }
        return result;
    }
};
