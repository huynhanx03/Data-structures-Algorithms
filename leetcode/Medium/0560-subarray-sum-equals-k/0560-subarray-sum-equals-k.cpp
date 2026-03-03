/*
 Problem: 560. Subarray Sum Equals K
 Language: cpp
 Runtime: 91 ms (24.50%)
 Memory: 49.1 MB (21.82%)
 Tags: Array, Hash Table, Prefix Sum
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        vector<int> ps(n + 1);
        ps[0] = 0;
        
        for (int i = 0; i < n; ++i) {
            ps[i + 1] = ps[i] + nums[i];
        }

        map<int, int> mp;

        for (int i = 1; i <= n; ++i) {
            if (ps[i] == k)
                ++ans;

            // ps[i] - x == k
            // -> x  = ps[i] - k
            if (mp.find(ps[i] - k) != mp.end()) {
                ans += mp[ps[i] - k];
                // ++ans;
            }

            ++mp[ps[i]];
        }

        return ans;
    } 
};