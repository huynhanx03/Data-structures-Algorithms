/*
 Problem: 4126. Minimum Number of Flips to Reverse Binary String
 Language: cpp
 Runtime: 3 ms (23.38%)
 Memory: 9 MB (65.38%)
 Tags: Math, Two Pointers, String, Bit Manipulation
*/
class Solution {
public:
    int minimumFlips(int n) {
        int cnt = 0;
        vector<bool> bits;
        while (n > 0) {
            bits.push_back(n % 2);
            n >>= 1;
        }
    
        for (int i = 0; i < bits.size() / 2; ++i) {
            cnt += (bits[i] != bits[bits.size() - i - 1]) * 2;    
        }   
        
        return cnt;
    }
};