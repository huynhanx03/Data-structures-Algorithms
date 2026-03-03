/*
 Problem: 2432. Number of Zero-Filled Subarrays
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 111.4 MB (42.39%)
 Tags: Array, Math
*/
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, cnt = 0;

        for (auto const& num: nums) {
            cnt = num == 0 ? cnt + 1 : 0;
            ans += cnt;
        }    

        return ans;
    }
};