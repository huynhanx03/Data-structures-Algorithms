/*
 Problem: 1975. Minimum Distance to the Target Element
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 13.2 MB (83.73%)
 Tags: Array
*/
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int mn = 1e9;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) mn = min(mn, abs(i - start));
        }

        return mn;   
    }
};