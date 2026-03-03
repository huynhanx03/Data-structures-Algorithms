/*
 Problem: 3455. Minimum Length of String After Operations
 Language: cpp
 Runtime: 22 ms (63.48%)
 Memory: 31.9 MB (89.17%)
 Tags: Hash Table, String, Counting
*/
class Solution {
public:
    int minimumLength(string s) {
        vector<int> cnt(26, 0);

        int ans = 0;

        for (const auto& c: s) {
            int v = c - 'a';
            
            ++ans;
            
            if (++cnt[v] >= 3) {
                cnt[v] -= 2;
                ans -= 2;
            }
        }

        return ans;
    }
};