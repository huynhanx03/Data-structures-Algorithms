/*
 Problem: 1631. Number of Sub-arrays With Odd Sum
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 112.1 MB (53.69%)
 Tags: Array, Math, Dynamic Programming, Prefix Sum
*/
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int sum = 0;    
        vector<int> cnt(2, 0);
        cnt[0] = 1;
        int ans = 0;
        const int MOD = 1e9 + 7;
        
        for (const auto& x : arr) {
            sum += x;
            ans = (ans + cnt[(sum % 2 + 1) % 2]) % MOD;
            ++cnt[sum % 2];
        }

        return ans;
    }
};