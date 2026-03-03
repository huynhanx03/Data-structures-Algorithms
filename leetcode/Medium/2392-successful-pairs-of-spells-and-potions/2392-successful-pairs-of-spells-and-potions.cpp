/*
 Problem: 2392. Successful Pairs of Spells and Potions
 Language: cpp
 Runtime: 50 ms (25.73%)
 Memory: 128.3 MB (46.47%)
 Tags: Array, Two Pointers, Binary Search, Sorting
*/
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        for (int spell : spells) {
            long long minPotion = (success + spell - 1) / spell;
            auto it = lower_bound(potions.begin(), potions.end(), minPotion);
            res.push_back(potions.end() - it);
        }
        return res;
    }
};