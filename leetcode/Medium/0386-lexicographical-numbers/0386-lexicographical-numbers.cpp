/*
 Problem: 386. Lexicographical Numbers
 Language: cpp
 Runtime: 2 ms (48.48%)
 Memory: 13.9 MB (79.46%)
 Tags: Depth-First Search, Trie
*/
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int cur = 1;

        for (int i = 0; i < n; ++i) {
            ans.push_back(cur);

            if (cur * 10 <= n) {
                cur *= 10;
            } else {
                while (cur % 10 == 9 || cur + 1 > n) {
                    cur /= 10;
                }
                ++cur;
            }
        }
        
        return ans;
    }
};