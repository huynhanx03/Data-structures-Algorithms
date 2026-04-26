/*
 Problem: 4282. Sort Vowels by Frequency
 Language: cpp
 Runtime: 13 ms (83.12%)
 Memory: 19.1 MB (54.65%)
 Tags: None
*/
class Solution {
public:
    string sortVowels(string s) {
        string v = "aeiou";
        vector<int> cnt(5), first(5, -1);

        auto id = [&](char c) {
            for (int i = 0; i < 5; ++i) {
                if (v[i] == c) return i;
            }

            return -1;
        };

        for (int i = 0; i < s.size(); ++i) {
            int x = id(s[i]);

            if (x == -1) continue;

            ++cnt[x];
            if (first[x] == -1) first[x] = i;
        }

        vector <int> ord = {0, 1, 2, 3, 4};
        sort(ord.begin(), ord.end(), [&](int a, int b) {
           if (cnt[a] != cnt[b]) return cnt[a] > cnt[b];
            return first[a] < first[b];
        });

        string seq;
        for (const auto& i : ord) seq += string(cnt[i], v[i]);

        int j = 0;
        for (char&c : s) if (id(c) != -1) c = seq[j++];
        return s;
    }
};