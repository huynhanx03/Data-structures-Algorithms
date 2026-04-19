/*
 Problem: 4284. Smallest Stable Index I
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 31.6 MB (5.12%)
 Tags: None
*/
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mx(n, 0), mn(n, 1e9);

        mx[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            mx[i] = max(mx[i - 1], nums[i]);
        }

        mn[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            mn[i] = min(mn[i + 1], nums[i]);
        }

        for (int i = 0; i < n; ++i) {
            if (mx[i] - mn[i] <= k) return i;
        }
        
        return -1;
    }
};