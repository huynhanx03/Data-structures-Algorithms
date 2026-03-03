/*
 Problem: 3846. Minimum Operations to Make Array Sum Divisible by K
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 45.3 MB (34.10%)
 Tags: Array, Math
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;

        for (const auto& num : nums) {
            sum += num;
        }

        return sum % k;
    }
};