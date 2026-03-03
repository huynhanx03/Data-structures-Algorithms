/*
 Problem: 2509. Minimize XOR
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8 MB (75.07%)
 Tags: Greedy, Bit Manipulation
*/
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = bitset<32>(num2).count();
        
        int r = 0;

        for (int i = 31; i >= 0 && cnt > 0; --i) {
            if (num1 & (1 << i)) {
                r |= (1 << i);
                --cnt;
            }
        }

        for (int i = 0; i <= 31 && cnt > 0; ++i) {
            if (!(r & (1 << i))) {
                r |= (1 << i);
                --cnt;
            }
        }

        return r;
    }
};