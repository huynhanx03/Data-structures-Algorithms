/*
 Problem: 2265. Partition Array According to Given Pivot
 Language: cpp
 Runtime: 8 ms (49.72%)
 Memory: 127.7 MB (79.12%)
 Tags: Array, Two Pointers, Simulation
*/
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int cnt = 0;
        int p = 0;
        vector<int> res(n);

        for (int i = 0; i < n; ++i) {
            if (nums[i] < pivot)
                res[p++] = nums[i];
            else if (nums[i] == pivot)
                ++cnt;
        }

        while (cnt--)
            res[p++] = pivot;

        for (int i = 0; i < n; ++i)
            if (nums[i] > pivot)
                res[p++] = nums[i];
        
        return res;
    }
};