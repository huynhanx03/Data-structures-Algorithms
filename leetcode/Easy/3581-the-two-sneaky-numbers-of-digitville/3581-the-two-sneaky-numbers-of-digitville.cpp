/*
 Problem: 3581. The Two Sneaky Numbers of Digitville
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 25.2 MB (91.35%)
 Tags: Array, Hash Table, Math
*/
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size() - 2, xor_all = 0;
        for (int x : nums) xor_all ^= x;
        for (int i = 0; i < n; i++) xor_all ^= i;
        int diff_bit = xor_all & -xor_all;
        int a = 0, b = 0;
        for (int x : nums) (x & diff_bit ? a : b) ^= x;
        for (int i = 0; i < n; i++) (i & diff_bit ? a : b) ^= i;
        return {a, b};
    }
};