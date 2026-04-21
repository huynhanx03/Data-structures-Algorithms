/*
 Problem: 397. Integer Replacement
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 7.8 MB (54.10%)
 Tags: Dynamic Programming, Greedy, Bit Manipulation, Memoization
*/
class Solution {
public:
    int integerReplacement(int n) {
        long long v = n;
        
        int step = 0;
        
        while (v != 1) {
            if (v&1) {
                if (v == 3 || v % 4 == 1) --v;
                else ++v;
            }
            else {
                v >>= 1;
            }
            ++step;
        }

        return step;
    }
};