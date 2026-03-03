/*
 Problem: 3437. Maximum Total Damage With Spell Casting
 Language: cpp
 Runtime: 274 ms (79.67%)
 Memory: 209.3 MB (78.61%)
 Tags: Array, Hash Table, Two Pointers, Binary Search, Dynamic Programming, Sorting, Counting
*/
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long, long long> sumDamage;
        for (const auto& p : power) sumDamage[p] += p;
        
        int n = sumDamage.size();

        vector<long long> keys;
        keys.reserve(n);
        
        for (const auto& kv : sumDamage) keys.push_back(kv.first);
        
        sort(keys.begin(), keys.end());
        vector<long long> dp(n);
        dp[0] = sumDamage[keys[0]];
        
        for (int i = 1; i < n; ++i) {
            long long take = sumDamage[keys[i]];
            
            int j = i - 1;
            
            while (j >= 0 && keys[i] - keys[j] <= 2) j--;
            
            if (j >= 0) take += dp[j];
            dp[i] = max(dp[i-1], take);
        }
        return dp[n-1];
    }
};
