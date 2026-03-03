/*
 Problem: 4183. Count Caesar Cipher Pairs
 Language: cpp
 Runtime: 28 ms (79.70%)
 Memory: 110.3 MB (79.84%)
 Tags: Array, Hash Table, Math, String, Counting
*/
class Solution {
public:
    long long countPairs(vector<string>& words) {
        long long cnt = 0;
        map <string, int> freq;
        for (const auto& w : words) {
            int v = w[0] - 'a';
            string tmp = w;
            for (int i = 0; i < tmp.size(); ++i) {
                int nv = tmp[i] - 'a';
                int next = (nv - v + 26) % 26;
                tmp[i] = next + 'a';
            }
            cnt += freq[tmp];
            ++freq[tmp];
        }

        return cnt;
    }
};