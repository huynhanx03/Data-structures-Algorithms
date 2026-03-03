/*
 Problem: 49. Group Anagrams
 Language: cpp
 Runtime: 37 ms (18.91%)
 Memory: 24.8 MB (91.02%)
 Tags: Array, Hash Table, String, Sorting
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> hm;

        for (auto str: strs) {
            string strSort = str;
            sort(strSort.begin(), strSort.end());

            hm[strSort].push_back(str);
        }

        vector<vector<string>> ans;

        for (auto vstring: hm)
            ans.push_back(vstring.second);

        return ans;
    }
};