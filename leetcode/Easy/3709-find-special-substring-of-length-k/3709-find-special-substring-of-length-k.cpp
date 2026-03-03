/*
 Problem: 3709. Find Special Substring of Length K
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.7 MB (34.43%)
 Tags: String
*/
class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        s = s + '-';    
        int n = s.size();
            int p = 0;

            for (int i = 1; i < n; ++i) {
                if (s[i] == s[i - 1]) {
                    continue;
                }

                if (i - p == k) {
                    return true;
                } else {
                    p = i;
                }
            }

            return false;
        }
};