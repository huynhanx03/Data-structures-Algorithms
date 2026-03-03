/*
 Problem: 2837. Minimum Operations to Make the Integer Zero
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.2 MB (46.93%)
 Tags: Bit Manipulation, Brainteaser, Enumeration
*/
class Solution {
public:
    int popcount(long long x) {
        int count = 0;
        while (x) {
            x &= (x - 1);
            count++;
        }
        return count;
    }

    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; k++) {
            long long x = num1 - 1LL * k * num2;
            
            if (x < 0) break;
            
            int bits = popcount(x);
            
            if (bits <= k && k <= x) {
                return k;
            }
        }
        return -1;
    }
};