/*
 Problem: 3622. Maximum Frequency of an Element After Performing Operations I
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 96.4 MB (100.00%)
 Tags: Array, Binary Search, Sliding Window, Sorting, Prefix Sum
*/
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal = *max_element(nums.begin(), nums.end()) + k + 2;
        vector<int> prefix(maxVal, 0);
        for (int x : nums)
            prefix[x]++;
        for (int i = 1; i < maxVal; i++)
            prefix[i] += prefix[i - 1];

        int ans = 0;
        for (int i = 0; i < maxVal; i++) {
            int cur = prefix[i] - (i > 0 ? prefix[i - 1] : 0);
            int left = max(0, i - k);
            int right = min(maxVal - 1, i + k);
            int allVal =
                prefix[right] - (left > 0 ? prefix[left - 1] : 0) - cur;
            ans = max(ans, min(allVal, numOperations) + cur);
        }
        return ans;
    }
};