/*
 Problem: 3616. Make Array Elements Equal to Zero
 Language: cpp
 Runtime: 3 ms (79.22%)
 Memory: 21.7 MB (98.77%)
 Tags: Array, Simulation, Prefix Sum
*/
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;
        int validSelections = 0, leftSum = 0;
        for (int num : nums) {
            leftSum += num;
            if (num != 0) continue;
            int rightSum = totalSum - leftSum;
            if (rightSum == leftSum || rightSum == leftSum + 1) validSelections++;
            if (rightSum == leftSum || rightSum == leftSum - 1) validSelections++;
        }
        return validSelections;
    }
};