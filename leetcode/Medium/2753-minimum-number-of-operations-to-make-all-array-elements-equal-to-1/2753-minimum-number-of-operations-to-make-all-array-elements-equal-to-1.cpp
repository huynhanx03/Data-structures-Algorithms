/*
 Problem: 2753. Minimum Number of Operations to Make All Array Elements Equal to 1
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 31.8 MB (10.04%)
 Tags: Array, Math, Number Theory
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), g = 0;
        for (int x : nums) g = gcd(g, x);
        if (g != 1) return -1;

        int ones = count(nums.begin(), nums.end(), 1);
        if (ones) return n - ones;

        int min_len = n + 1;
        for (int i = 0; i < n; ++i) {
            int g = nums[i];
            for (int j = i + 1; j < n; ++j) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    min_len = min(min_len, j - i + 1);
                    break;
                }
            }
        }
        return (n - 1) + (min_len - 1);
    }
};