/*
 Problem: 169. Majority Element
 Language: cpp
 Runtime: 10 ms (8.17%)
 Memory: 27.1 MB (99.97%)
 Tags: Array, Hash Table, Divide and Conquer, Sorting, Counting
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;

        for (auto& num : nums)
            ++mp[num];

        int cnt = 0;
        int ans = -1;

        for (auto& it : mp) {
            if (it .second > cnt) {
                cnt = it .second;
                ans = it .first;
            }
        }

        return ans;
    }
};