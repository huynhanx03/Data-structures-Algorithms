/*
 Problem: 717. 1-bit and 2-bit Characters
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 13.1 MB (80.08%)
 Tags: Array
*/
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;

        while (i < n - 1) {
            if (bits[i]) ++i;
            ++i;
        }

        return i == n - 1;
    }
};