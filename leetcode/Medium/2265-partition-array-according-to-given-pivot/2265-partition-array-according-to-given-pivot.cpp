/*
 Problem: 2265. Partition Array According to Given Pivot
 Language: cpp
 Runtime: 2 ms (89.52%)
 Memory: 141 MB (15.65%)
 Tags: Array, Two Pointers, Simulation
*/
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less_than_pivot;
        vector<int> equal_to_pivot;
        vector<int> greater_than_pivot;

        for (int num : nums) {
            if (num < pivot) {
                less_than_pivot.push_back(num);
            } else if (num == pivot) {
                equal_to_pivot.push_back(num);
            } else {
                greater_than_pivot.push_back(num);
            }
        }

        vector<int> result;
        result.insert(result.end(), less_than_pivot.begin(),
                      less_than_pivot.end());
        result.insert(result.end(), equal_to_pivot.begin(),
                      equal_to_pivot.end());
        result.insert(result.end(), greater_than_pivot.begin(),
                      greater_than_pivot.end());

        return result;
    }
};