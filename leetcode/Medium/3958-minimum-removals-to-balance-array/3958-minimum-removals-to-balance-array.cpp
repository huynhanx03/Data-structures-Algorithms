/*
 Problem: 3958. Minimum Removals to Balance Array
 Language: cpp
 Runtime: 35 ms (42.74%)
 Memory: 105.1 MB (51.37%)
 Tags: Array, Binary Search, Sliding Window, Sorting
*/
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, best = 0;

        for (int j = 0; j < n; ++j) {
            while ((long long)nums[j] > (long long)k * nums[i]) {
                ++i;
            }
            best = max(best, j - i + 1);
        }

        return n - best;
    }
};
