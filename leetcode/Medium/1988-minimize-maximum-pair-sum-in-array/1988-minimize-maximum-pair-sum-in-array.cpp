/*
 Problem: 1988. Minimize Maximum Pair Sum in Array
 Language: cpp
 Runtime: 170 ms (59.42%)
 Memory: 100 MB (66.06%)
 Tags: Array, Two Pointers, Greedy, Sorting
*/
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;

        int ans = 0;
        while (l <= r) {
            ans = max(ans, nums[l] + nums[r]);
            
            ++l;
            --r;
        }

        return ans;
    }
};