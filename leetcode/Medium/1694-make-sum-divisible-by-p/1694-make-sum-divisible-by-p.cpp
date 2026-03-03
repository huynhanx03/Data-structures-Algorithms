/*
 Problem: 1694. Make Sum Divisible by P
 Language: cpp
 Runtime: 59 ms (98.04%)
 Memory: 87.8 MB (68.98%)
 Tags: Array, Hash Table, Prefix Sum
*/
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) total += x;
        int target = total % p;
        if (target == 0) return 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int res = nums.size();
        long long prefix = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i]) % p;
            int need = (prefix - target + p) % p;
            if (mp.count(need)) res = min(res, i - mp[need]);
            mp[prefix] = i;
        }
        return res == nums.size() ? -1 : res;
    }
};