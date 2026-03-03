/*
 Problem: 438. Find All Anagrams in a String
 Language: cpp
 Runtime: 5 ms (55.77%)
 Memory: 11.4 MB (97.16%)
 Tags: Hash Table, String, Sliding Window
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len = p.size();
        int n = s.size();

        vector<int> cnt(26, 0);

        for (const auto& c : p) {
            --cnt[c - 'a'];
        }

        vector<int> ans;

        for (int i = 0; i < n; ++i) {
            ++cnt[s[i] - 'a'];
            if (i >= len - 1) {
                if (i - len >= 0) --cnt[s[i - len] - 'a'];

                int count = 0;

                for (int j = 0; j < 26; ++j) count += abs(cnt[j]);

                if (count == 0) ans.push_back(i - len + 1);
            }
        }

        return ans;
    }
};