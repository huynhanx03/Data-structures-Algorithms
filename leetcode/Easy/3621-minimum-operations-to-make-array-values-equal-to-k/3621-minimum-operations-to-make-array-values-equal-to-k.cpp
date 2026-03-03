/*
 Problem: 3621. Minimum Operations to Make Array Values Equal to K
 Language: cpp
 Runtime: 12 ms (57.56%)
 Memory: 32.4 MB (57.14%)
 Tags: Array, Hash Table
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int, int> mp;

        for (const auto& num : nums) {
            if (num < k) return -1;
            if (num != k) mp[num] = -1;
        }

        return mp.size();
    }
};