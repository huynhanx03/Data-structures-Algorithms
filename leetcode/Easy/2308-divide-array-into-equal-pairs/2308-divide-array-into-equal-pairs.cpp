/*
 Problem: 2308. Divide Array Into Equal Pairs
 Language: cpp
 Runtime: 9 ms (12.75%)
 Memory: 18.3 MB (26.75%)
 Tags: Array, Hash Table, Bit Manipulation, Counting
*/
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int, int> mp;
        
        for (const auto& x : nums)
            ++mp[x];

        for (auto& p : mp)
            if (p.second & 1) return false;

        return true;
    }
};
