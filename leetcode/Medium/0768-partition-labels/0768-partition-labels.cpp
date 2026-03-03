/*
 Problem: 768. Partition Labels
 Language: cpp
 Runtime: 3 ms (26.92%)
 Memory: 9.7 MB (5.10%)
 Tags: Hash Table, Two Pointers, String, Greedy
*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        
        map<char, int> mp;

        int start = 0;
        int end = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            mp[s[i]] = i; // last
        }

        for (int i = 0; i < n; ++i) {
            end = max(end, mp[s[i]]);

            if (end == i) {
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }

        return ans;
    }
};