/*
 Problem: 2478. Longest Nice Subarray
 Language: cpp
 Runtime: 1 ms (42.51%)
 Memory: 60.8 MB (89.23%)
 Tags: Array, Bit Manipulation, Sliding Window
*/
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int bits = 0, left = 0, res = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while ((left <= right) && ((bits & nums[right]) != 0))
                bits ^= nums[left++];

            bits |= nums[right];

            res = max(res, right - left + 1);
        }

        return res;
    }
};