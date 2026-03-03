/*
 Problem: 2448. Count Number of Bad Pairs
 Language: cpp
 Runtime: 82 ms (17.13%)
 Memory: 92.7 MB (8.40%)
 Tags: Array, Hash Table, Math, Counting
*/
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();

        long long totalPairs = (long long)n * (n - 1) / 2;
        
        unordered_map<int, long long> diffCount;
        
        for (int i = 0; i < n; i++) {
            int diff = nums[i] - i;
            totalPairs -= diffCount[diff];
            diffCount[diff]++;
        }

        return totalPairs;
    }
};