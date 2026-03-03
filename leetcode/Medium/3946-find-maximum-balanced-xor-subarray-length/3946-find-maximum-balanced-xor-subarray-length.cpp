/*
 Problem: 3946. Find Maximum Balanced XOR Subarray Length
 Language: cpp
 Runtime: 729 ms (69.01%)
 Memory: 350.9 MB (49.32%)
 Tags: Array, Hash Table, Bit Manipulation, Prefix Sum
*/
class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        map<long long, int> mp;
        int px = 0, bal = 0, best = 0;

        auto key = [&](int x, int y) {
            return ((long long) x << 32) ^ (unsigned long long)(y & 0xffffffff);
        };

        mp[key(0, 0)] = -1;

        for (int i = 0; i < nums.size(); ++i) {
            px ^= nums[i];
            bal += (nums[i] % 2 == 0 ? 1 : -1);

            long long k = key(px, bal);

            if (mp.count(k)) {
                best = max(best, i - mp[k]);
            } else {
                mp[k] = i;
            }
        }

        return best;
    }
};