/*
 Problem: 3705. Find the Largest Almost Missing Integer
 Language: cpp
 Runtime: 15 ms (11.70%)
 Memory: 32.8 MB (20.57%)
 Tags: Array, Hash Table
*/
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int n = nums.size();
        
        // Count the frequency of each number in every subarray of size k
        for (int i = 0; i <= n - k; ++i) {
            unordered_map<int, bool> seen;
            for (int j = i; j < i + k; ++j) {
                if (!seen[nums[j]]) {
                    count[nums[j]]++;
                    seen[nums[j]] = true;
                }
            }
        }
        
        int result = -1;
        for (auto& [num, freq] : count) {
            if (freq == 1) {
                result = max(result, num);
            }
        }
        
        return result;
    }
};