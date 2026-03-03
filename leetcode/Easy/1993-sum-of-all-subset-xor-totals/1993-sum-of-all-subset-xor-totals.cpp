/*
 Problem: 1993. Sum of All Subset XOR Totals
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 9.1 MB (66.33%)
 Tags: Array, Math, Backtracking, Bit Manipulation, Combinatorics, Enumeration
*/
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        for (int i = 0; i < n; ++i)
            res |= nums[i];
        for (int i = 0; i < n - 1; ++i)
            res *= 2;

        return res;
    }
};