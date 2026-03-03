/*
 Problem: 1849. Maximum Absolute Sum of Any Subarray
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 45 MB (86.81%)
 Tags: Array, Dynamic Programming
*/
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_sum = 0, min_sum = 0, sum = 0, max_ans = 0, min_ans = 0;
        
        for (int num : nums) {
            sum += num;
            max_sum = max(max_sum + num, num);
            max_ans = max(max_ans, max_sum);
            min_sum = min(min_sum + num, num);
            min_ans = min(min_ans, min_sum);
        }
        
        return max(max_ans, abs(min_ans));
    }
};
