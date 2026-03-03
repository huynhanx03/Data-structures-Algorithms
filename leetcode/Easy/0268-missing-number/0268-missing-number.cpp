/*
 Problem: 268. Missing Number
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 21.8 MB (69.50%)
 Tags: Array, Hash Table, Math, Binary Search, Bit Manipulation, Sorting
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n + 1) / 2;

        for (const auto& num : nums) {
            sum -= num;
        }

        return sum;
    }
};