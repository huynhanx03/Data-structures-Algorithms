/*
 Problem: 4086. Lexicographically Smallest String After Deleting Duplicate Characters
 Language: cpp
 Runtime: 104 ms (57.20%)
 Memory: 42.4 MB (28.44%)
 Tags: Hash Table, String, Stack, Greedy, Monotonic Stack
*/
class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        vector <int> cnt(26);
        for (const auto& c : s) ++cnt[c - 'a'];

        string res = "";

        vector <int> incnt(26);

        for (const auto& c : s) {
            --cnt[c - 'a'];
            while (!res.empty() && res.back() > c) {
                char top = res.back();
                if (cnt[top - 'a'] > 0 || incnt[top - 'a'] > 1) {
                    --incnt[top - 'a'];
                    res.pop_back();
                } else {
                    break;
                }
            }

            res.push_back(c);
            ++incnt[c - 'a'];
        }

        while (!res.empty()) {
            char b = res.back();
            if (incnt[b - 'a'] > 1) {
                --incnt[b - 'a'];
                res.pop_back();
            } else {
                break;
            }
        }
        
        return res;
    }
};