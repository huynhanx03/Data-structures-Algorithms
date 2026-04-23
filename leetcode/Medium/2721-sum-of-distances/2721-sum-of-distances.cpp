/*
 Problem: 2721. Sum of Distances
 Language: cpp
 Runtime: 71 ms (56.25%)
 Memory: 116.9 MB (59.25%)
 Tags: Array, Hash Table, Prefix Sum
*/
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);
        
        unordered_map<int, vector<int>> mp;
        
        for (int i = 0; i < n; ++i) {
            mp[nums[i]].push_back(i);
        }
        
        for (const auto& [_, pos] : mp) {
            int k = pos.size();
            
            vector<long long> prefix(k + 1, 0);
            for (int i = 0; i < k; ++i) {
                prefix[i + 1] = prefix[i] + pos[i];
            }
            
            for (int i = 0; i < k; ++i) {
                long long left = (long long)pos[i] * i - prefix[i];
                long long right = (prefix[k] - prefix[i + 1]) - (long long)pos[i] * (k - i - 1);
                ans[pos[i]] = left + right;
            }
        }
        
        return ans;
    }
};