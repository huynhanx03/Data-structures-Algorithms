/*
 Problem: 3620. Maximum Number of Distinct Elements After Operations
 Language: cpp
 Runtime: 129 ms (25.46%)
 Memory: 97.8 MB (37.27%)
 Tags: Array, Greedy, Sorting
*/
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int last = INT_MIN;
        int res = 0;
        for (int x : nums) {
            int candidate = max(last + 1, x - k);
            if (candidate <= x + k) {
                res++;
                last = candidate;
            }
        }
        return res;
    }
};