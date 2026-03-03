/*
 Problem: 217. Contains Duplicate
 Language: cpp
 Runtime: 67 ms (17.48%)
 Memory: 74.6 MB (73.11%)
 Tags: Array, Hash Table, Sorting
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> cnt;

        for (const auto& x : nums) {
            ++cnt[x];
            if (cnt[x] >= 2) return true;
        }

        return false;
    }
};