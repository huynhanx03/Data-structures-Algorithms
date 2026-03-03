/*
 Problem: 3. Longest Substring Without Repeating Characters
 Language: cpp
 Runtime: 3 ms (79.42%)
 Memory: 11.6 MB (74.59%)
 Tags: Hash Table, String, Sliding Window
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};