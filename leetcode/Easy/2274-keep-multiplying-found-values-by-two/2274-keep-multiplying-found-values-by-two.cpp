/*
 Problem: 2274. Keep Multiplying Found Values by Two
 Language: cpp
 Runtime: 5 ms (22.59%)
 Memory: 13.9 MB (89.95%)
 Tags: Array, Hash Table, Sorting, Simulation
*/
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for (const auto& num : nums) {
            original = original * (num == original ? 2 : 1);
        }

        return original;
    }
};