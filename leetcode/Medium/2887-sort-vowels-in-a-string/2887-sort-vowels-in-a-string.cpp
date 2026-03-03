/*
 Problem: 2887. Sort Vowels in a String
 Language: cpp
 Runtime: 21 ms (29.13%)
 Memory: 16 MB (60.98%)
 Tags: String, Sorting
*/
class Solution {
public:
    string sortVowels(string s) {
        string vowels_set = "aeiouAEIOU";

        auto isVowel = [&](char c) {
            return vowels_set.find(c) != string::npos;
        };

        vector<char> vowels;
        for (const char& c : s) {
            if (isVowel(c)) vowels.push_back(c);
        }
        sort(vowels.begin(), vowels.end());

        int n = s.size();
        int idx = 0;
        
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[idx++];
            }
        }

        return s;
    }
};