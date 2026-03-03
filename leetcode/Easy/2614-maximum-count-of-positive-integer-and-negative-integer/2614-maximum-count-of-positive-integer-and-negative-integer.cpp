/*
 Problem: 2614. Maximum Count of Positive Integer and Negative Integer
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 21.6 MB (25.43%)
 Tags: Array, Binary Search, Counting
*/
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negCount = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int posCount = nums.end() - lower_bound(nums.begin(), nums.end(), 1);
        return max(negCount, posCount);
    }
};
