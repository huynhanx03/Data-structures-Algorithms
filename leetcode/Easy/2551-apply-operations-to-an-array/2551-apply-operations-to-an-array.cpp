/*
 Problem: 2551. Apply Operations to an Array
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 13.2 MB (27.52%)
 Tags: Array, Two Pointers, Simulation
*/
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        vector<int> result;

        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }

            if (nums[i]) {
                result.push_back(nums[i]);
                ++cnt;
            }
        }

        if (nums[n - 1]) {
            result.push_back(nums[n - 1]);
            ++cnt;
        }

        while (cnt < n) {
            result.push_back(0);
            ++cnt;
        }

        return result;
    }
};