/*
 Problem: 1586. Longest Subarray of 1's After Deleting One Element
 Language: cpp
 Runtime: 2 ms (30.34%)
 Memory: 60 MB (78.23%)
 Tags: Array, Dynamic Programming, Sliding Window
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector <int> cnt(2, 0);
        int ans = 0;
        bool isDelete = 1;

        for (const auto& num : nums) {
            if (num) {
                ++cnt[1];
            } else {
                ans = max(ans, cnt[0] + cnt[1]);
                cnt[0] = cnt[1];
                cnt[1] = 0;
                isDelete = 0;
            }
        }

        return max(ans, cnt[0] + cnt[1] - isDelete);
    }
};