/*
 Problem: 3731. Sum of Variable Length Subarrays
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 27.5 MB (22.53%)
 Tags: Array, Prefix Sum
*/
class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        
        vector <int> ps(n + 5, 0);
        
        for (int i = 0; i < n; ++i) {
            ps[i + 1] = ps[i] + nums[i];
        }
        
        int sum = 0;
        
        for (int i = 0; i < n; ++i) {
            int s = max(0, i - nums[i]);
            
            sum += ps[i + 1] - ps[s];
        }
        
        return sum;
    }
};