/*
 Problem: 3704. Count Partitions with Even Sum Difference
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 22.5 MB (22.86%)
 Tags: Array, Math, Prefix Sum
*/
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }

        return sum % 2 != 0 ? 0 : nums.size() - 1;
    }
};