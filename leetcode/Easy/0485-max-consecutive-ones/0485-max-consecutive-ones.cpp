/*
 Problem: 485. Max Consecutive Ones
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 50.2 MB (67.30%)
 Tags: Array
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;

        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) ++cnt;
            else {
                ans = max(ans, cnt);
                cnt = 0;
            }
        }

        return max(cnt, ans);
    }
};