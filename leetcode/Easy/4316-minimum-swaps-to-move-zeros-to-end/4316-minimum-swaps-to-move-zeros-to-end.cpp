/*
 Problem: 4316. Minimum Swaps to Move Zeros to End
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 31.6 MB (99.47%)
 Tags: Array, Two Pointers
*/
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size(), cnt0 = 0;
        for (const auto& x : nums) if (x == 0) ++cnt0;

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0 && i < n - cnt0) ++ans;
        }

        return ans;
    }
};