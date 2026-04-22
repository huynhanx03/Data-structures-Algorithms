/*
 Problem: 2550. Words Within Two Edits of Dictionary
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 12.5 MB (70.59%)
 Tags: Array, String, Trie
*/
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        
        for (const auto &q : queries) {
            bool ok = false;
            
            for (const auto &d : dictionary) {
                int diff = 0;
                for (int i = 0; i < q.size(); ++i) {
                    if (q[i] != d[i]) {
                        ++diff;
                        if (diff > 2) break;
                    }
                }
                if (diff <= 2) {
                    ok = true;
                    break;
                }
            }
            
            if (ok) ans.push_back(q);
        }
        
        return ans;
    }
};