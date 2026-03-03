/*
 Problem: 1006. Vowel Spellchecker
 Language: cpp
 Runtime: 38 ms (62.72%)
 Memory: 41.5 MB (65.37%)
 Tags: Array, Hash Table, String
*/
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> lower_map;
        unordered_map<string, string> vowel_map;

        auto devowel = [&](const string& w) {
            string res = "";
            for (char c : w) {
                char lc = tolower(c);
                res += (lc=='a'||lc=='e'||lc=='i'||lc=='o'||lc=='u') ? '*' : lc;
            }
            
            return res;
        };

        for (string& w : wordlist) {
            string lw;
            for (char c : w) lw.push_back(tolower(c));
            if (!lower_map.count(lw)) lower_map[lw] = w;
            string mask = devowel(w);
            if (!vowel_map.count(mask)) vowel_map[mask] = w;
        }

        vector<string> ans;
        for (string q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }
            string lq;
            for (char c : q) lq.push_back(tolower(c));
            if (lower_map.count(lq)) {
                ans.push_back(lower_map[lq]);
                continue;
            }
            string mask = devowel(q);
            if (vowel_map.count(mask)) {
                ans.push_back(vowel_map[mask]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};