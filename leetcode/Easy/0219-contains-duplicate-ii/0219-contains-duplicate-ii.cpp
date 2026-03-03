/*
 Problem: 219. Contains Duplicate II
 Language: cpp
 Runtime: 180 ms (10.79%)
 Memory: 84.5 MB (91.30%)
 Tags: Array, Hash Table, Sliding Window
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mp;

        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                mp[nums[i]] = 0; 
            } else {
                if (mp[nums[i]] == 0) {
                    if (nums[i] == nums[0]) {
                        if (i <= k)
                            return 1;
                    }

                } else {
                    if (i - mp[nums[i]] <= k)
                        return 1;
                }

                mp[nums[i]] = i; 
            }
        }

        return 0;
    }
};