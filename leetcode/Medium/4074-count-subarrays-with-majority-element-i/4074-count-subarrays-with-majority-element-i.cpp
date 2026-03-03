/*
 Problem: 4074. Count Subarrays With Majority Element I
 Language: cpp
 Runtime: 55 ms (31.11%)
 Memory: 39.7 MB (58.42%)
 Tags: Array, Hash Table, Divide and Conquer, Segment Tree, Merge Sort, Counting, Prefix Sum
*/
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
    
        for (int i = 0; i < n; ++i) {
            int cnt = 0;

            for (int j = i; j < n; ++j) {
                if (nums[j] == target) ++cnt;
                int len = j - i + 1;
                if (cnt > len / 2) {
                    ++ans;
                }
            }
        }
        
        return ans;
    }
};