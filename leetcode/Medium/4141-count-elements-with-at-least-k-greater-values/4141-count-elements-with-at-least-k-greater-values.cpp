/*
 Problem: 4141. Count Elements With at Least K Greater Values
 Language: cpp
 Runtime: 71 ms (50.90%)
 Memory: 173.9 MB (76.90%)
 Tags: Array, Binary Search, Divide and Conquer, Sorting, Quickselect
*/
class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) return n;

        sort(nums.begin(), nums.end());
        int tmp = nums[n - k];
        int cnt = 0;

        for (const auto&x : nums) {
            if (x < tmp) ++cnt;
        }

        return cnt;
    }
};