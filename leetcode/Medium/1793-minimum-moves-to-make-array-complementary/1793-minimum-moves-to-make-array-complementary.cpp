/*
 Problem: 1793. Minimum Moves to Make Array Complementary
 Language: cpp
 Runtime: 4 ms (80.08%)
 Memory: 93.5 MB (14.33%)
 Tags: Array, Hash Table, Prefix Sum
*/
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {
            int a = nums[i];
            int b = nums[n - 1 - i];

            int low = 1 + min(a, b);
            int high = limit + max(a, b);
            int sum = a + b;

            diff[2] += 2;

            diff[low] -= 1;
            diff[high + 1] += 1;

            diff[sum] -= 1;
            diff[sum + 1] += 1;
        }

        int ans = n;
        int cur = 0;

        for (int target = 2; target <= 2 * limit; target++) {
            cur += diff[target];
            ans = min(ans, cur);
        }

        return ans;
    }
};