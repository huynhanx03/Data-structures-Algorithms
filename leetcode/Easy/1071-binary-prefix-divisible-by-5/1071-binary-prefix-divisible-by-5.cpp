/*
 Problem: 1071. Binary Prefix Divisible By 5
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 18.3 MB (95.86%)
 Tags: Array, Bit Manipulation
*/
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        long long sum = 0;

        for (const auto& num : nums) {
            sum = (sum * 2 + num) % 5;
            ans.push_back(sum == 0);
        }

        return ans;
    }
};