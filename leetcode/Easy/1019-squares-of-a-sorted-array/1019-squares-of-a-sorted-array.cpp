/*
 Problem: 1019. Squares of a Sorted Array
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 30.3 MB (37.08%)
 Tags: Array, Two Pointers, Sorting
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int p1 = 0, p2 = n - 1;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; --i) {
            if (abs(nums[p1]) > abs(nums[p2])) {
                ans[i] = nums[p1] * nums[p1];
                ++p1;
            } else {
                ans[i] = nums[p2] * nums[p2];
                --p2;
            }
        }

        return ans;
    }
};
