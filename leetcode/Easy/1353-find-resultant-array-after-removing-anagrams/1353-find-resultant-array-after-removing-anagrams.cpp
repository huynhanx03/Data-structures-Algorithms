/*
 Problem: 1353. Find Resultant Array After Removing Anagrams
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 16 MB (91.18%)
 Tags: Array, Hash Table, String, Sorting
*/
class Solution {
private:
    const long long MOD = 1e9 + 7;

    long long fastPow(long long a, int b) {
        long long res = 1;
        while(b > 0) {
            if(b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    long long hashWord(const string& s) {
        long long hashVal = 0;
        for(char c : s) {
            int idx = c - 'a';
            hashVal = (hashVal + (idx + 1) * fastPow(13, idx) % MOD) % MOD;
        }
        return hashVal;
    }

public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        if(words.empty()) return result;
        result.push_back(words[0]);
        for(int i = 1; i < words.size(); i++) {
            if(hashWord(result.back()) != hashWord(words[i]))
                result.push_back(words[i]);
        }
        return result;
    }
};