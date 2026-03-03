/*
 Problem: 3476. Find Minimum Operations to Make All Elements Divisible by Three
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 23.2 MB (49.60%)
 Tags: Array, Math
*/
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        
        for (const auto& num : nums) {
            int tmp = num % 3;
            ans += min(3 - tmp, tmp);
        }

        return ans;
    }
};