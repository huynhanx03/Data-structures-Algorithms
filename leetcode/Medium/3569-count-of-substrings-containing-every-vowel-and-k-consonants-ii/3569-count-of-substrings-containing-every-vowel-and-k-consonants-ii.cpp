/*
 Problem: 3569. Count of Substrings Containing Every Vowel and K Consonants II
 Language: cpp
 Runtime: 201 ms (43.04%)
 Memory: 30.6 MB (93.35%)
 Tags: Hash Table, String, Sliding Window
*/
class Solution {
private:
    string vw = "aeiou";
    long long countAtLeastK(string& w, int k) {
        long long res = 0;
        int j = 0, need = 0;
        vector<int> cnt(6);

        for (int i = 0; i < w.size(); ++i) {
            int p = vw.find(w[i]) + 1;
            need += ++cnt[p] == 1 && p;
            while (need == 5 && cnt[0] >= k) {
                res += w.size() - i;
                int p = vw.find(w[j++]) + 1;
                need -= --cnt[p] == 0 && p;
            }
        }
        return res;
    }

public:
    long long countOfSubstrings(string w, int k) {
        return countAtLeastK(w, k) - countAtLeastK(w, k + 1);
    }
};