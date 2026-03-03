/*
 Problem: 3242. Count Elements With Maximum Frequency
 Language: cpp
 Runtime: 2 ms (30.05%)
 Memory: 23.2 MB (36.11%)
 Tags: Array, Hash Table, Counting
*/
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> cnt(101, 0);
        
        int mx = 0, ans = 0;

        for (const auto& num : nums) {
            mx = max(mx, ++cnt[num]);
        }

        for (const auto& c : cnt) {
            ans += c == mx ? mx : 0;
        }

        return ans;
    }
};