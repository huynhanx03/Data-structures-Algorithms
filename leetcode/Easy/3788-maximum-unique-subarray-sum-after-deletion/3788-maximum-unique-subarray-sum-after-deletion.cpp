/*
 Problem: 3788. Maximum Unique Subarray Sum After Deletion
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 29.5 MB (81.35%)
 Tags: Array, Hash Table, Greedy
*/
class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> st;
        int mn = -1e9;
        
        for (const auto&x : nums) {
            if (x > 0) st.insert(x);
            else mn = max(mn, x);
        }

        int res = 0;
        
        for (const auto&x : st) {
            res += x;
        }

        return st.size() ? res : mn;
    }
};