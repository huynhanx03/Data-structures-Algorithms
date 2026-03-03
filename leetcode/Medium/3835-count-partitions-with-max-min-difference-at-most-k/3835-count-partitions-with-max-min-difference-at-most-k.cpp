/*
 Problem: 3835. Count Partitions With Max-Min Difference at Most K
 Language: cpp
 Runtime: 263 ms (18.54%)
 Memory: 232.1 MB (11.46%)
 Tags: Array, Dynamic Programming, Queue, Sliding Window, Prefix Sum, Monotonic Queue
*/
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();

        multiset<int> st;
        vector<long long> dp(n + 1), pref(n + 1);
        
        dp[0] = pref[0] = 1;

        int left = 0;

        for (int right = 0; right < n; right++) {
            st.insert(nums[right]);

            while (*st.rbegin() - *st.begin() > k) {
                st.erase(st.find(nums[left]));
                left++;
            }

            long long total = pref[right] - (left ? pref[left - 1] : 0);
            total = (total % MOD + MOD) % MOD;

            dp[right + 1] = total;
            pref[right + 1] = (pref[right] + dp[right + 1]) % MOD;
        }

        return dp[n];
    }
};