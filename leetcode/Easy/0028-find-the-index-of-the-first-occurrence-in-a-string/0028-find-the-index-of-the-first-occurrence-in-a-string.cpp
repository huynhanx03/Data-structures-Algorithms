/*
 Problem: 28. Find the Index of the First Occurrence in a String
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.5 MB (99.97%)
 Tags: Two Pointers, String, String Matching
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m == 0)
            return 0;

        for (int i = 0; i <= n - m; ++i) {
            bool match = true;
            for (int j = 0; j < m; ++j) {
                if (haystack[i + j] != needle[j]) {
                    match = false;
                    break;
                }
            }
            if (match)
                return i;
        }

        return -1;
    }
};