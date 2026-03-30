/*
 Problem: 2978. Check if Strings Can be Made Equal With Operations II
 Language: cpp
 Runtime: 8 ms (55.17%)
 Memory: 19.9 MB (62.64%)
 Tags: Hash Table, String, Sorting
*/
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<vector<int>> cnt(2, vector<int>(26, 0));

        for (int i = 0; i < s1.size(); ++i) {
            int p = i % 2;
            cnt[p][s1[i] - 'a']++;
            cnt[p][s2[i] - 'a']--;
        }

        return cnt[0] == cnt[1] && 
               all_of(cnt[0].begin(), cnt[0].end(), [](int x){ return x == 0; });
    }
};