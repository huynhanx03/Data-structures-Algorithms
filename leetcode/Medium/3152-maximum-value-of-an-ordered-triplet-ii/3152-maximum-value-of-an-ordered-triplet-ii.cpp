/*
 Problem: 3152. Maximum Value of an Ordered Triplet II
 Language: cpp
 Runtime: 4 ms (58.06%)
 Memory: 98.9 MB (23.75%)
 Tags: Array
*/
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n, 0), rightMax(n, 0);

        leftMax[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            leftMax[i] = max(leftMax[i - 1], nums[i]);
        }

        rightMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        }

        long long maxValue = 0;
        for (int i = 1; i < n - 1; ++i) {
            maxValue = max(maxValue, 1LL* (leftMax[i - 1] - nums[i]) * rightMax[i + 1]);
        }

        return maxValue;      
    }
};