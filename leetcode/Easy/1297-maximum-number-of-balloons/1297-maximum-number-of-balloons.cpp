/*
 Problem: 1297. Maximum Number of Balloons
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.8 MB (69.04%)
 Tags: Hash Table, String, Counting
*/
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnt(26);

        for (const auto& c : text) {
            ++cnt[c - 'a'];
        }

        return min({
            cnt['b' - 'a'],
            cnt['a' - 'a'],
            cnt['l' - 'a'] >> 1,
            cnt['o' - 'a'] >> 1,
            cnt['n' - 'a']
        });
    }
};