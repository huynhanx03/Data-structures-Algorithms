/*
 Problem: 3651. Transformed Array
 Language: cpp
 Runtime: 10 ms (24.39%)
 Memory: 25.6 MB (72.14%)
 Tags: Array, Simulation
*/
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                res[i] = nums[i];
            } else {
                res[i] = nums[((nums[i] + i + n) % n + n) % n];
            }
        }

        return res;
    }
};