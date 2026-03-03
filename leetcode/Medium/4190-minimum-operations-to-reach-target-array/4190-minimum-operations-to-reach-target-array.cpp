/*
 Problem: 4190. Minimum Operations to Reach Target Array
 Language: cpp
 Runtime: 108 ms (45.27%)
 Memory: 257.5 MB (43.43%)
 Tags: Array, Hash Table, Greedy
*/
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_set<int> st;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (nums[i] != target[i]) {
                st.insert(nums[i]);
            }
        }

        return st.size();
    }
};