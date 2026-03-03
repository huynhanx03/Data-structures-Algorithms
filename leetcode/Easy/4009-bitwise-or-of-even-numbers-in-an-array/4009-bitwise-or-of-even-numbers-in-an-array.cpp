/*
 Problem: 4009. Bitwise OR of Even Numbers in an Array
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 24.6 MB (37.87%)
 Tags: Array, Bit Manipulation, Simulation
*/
class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int res = 0;
        for (int x : nums) {
            if (x % 2 == 0) res |= x;
        }
        return res;
    }
};
