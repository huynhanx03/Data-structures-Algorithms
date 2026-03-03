/*
 Problem: 4129. Number of Centered Subarrays
 Language: cpp
 Runtime: 195 ms (84.35%)
 Memory: 88 MB (24.22%)
 Tags: Array, Hash Table, Enumeration
*/
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < nums.size(); ++i) {
            set<long long> st;
            long long sum = 0;

            for (int j = i; j < nums.size(); ++j) {
                sum += 1ll * nums[j];
                st.insert(nums[j]);
                if (st.count(sum)) ++ans;
            }
        }
        
        return ans;
    }
};