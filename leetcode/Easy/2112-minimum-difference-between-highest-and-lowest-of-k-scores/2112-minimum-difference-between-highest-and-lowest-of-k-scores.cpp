/*
 Problem: 2112. Minimum Difference Between Highest and Lowest of K Scores
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 17.3 MB (21.45%)
 Tags: Array, Sliding Window, Sorting
*/
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1e9;

        for (int i = 0; i + k <= nums.size(); ++i) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }

        return ans;
    }
};