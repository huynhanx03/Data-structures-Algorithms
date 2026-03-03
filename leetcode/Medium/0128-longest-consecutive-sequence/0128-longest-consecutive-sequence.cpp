/*
 Problem: 128. Longest Consecutive Sequence
 Language: cpp
 Runtime: 984 ms (5.09%)
 Memory: 74.7 MB (77.36%)
 Tags: Array, Hash Table, Union-Find
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : nums) {
            if (numSet.find(num - 1) == numSet.end()) {
                int length = 1;

                while (numSet.find(num + length) != numSet.end()) {
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};