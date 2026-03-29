/*
 Problem: 2999. Check if Strings Can be Made Equal With Operations I
 Language: cpp
 Runtime: 3 ms (14.84%)
 Memory: 8.6 MB (32.90%)
 Tags: String
*/
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        vector<int> even(26, 0), odd(26, 0);

        for (int i = 0; i < s1.size(); ++i) {
            if (i % 2 == 0) {
                ++even[s1[i] - 'a'];
                --even[s2[i] - 'a'];
            } else {
                ++odd[s1[i] - 'a'];
                --odd[s2[i] - 'a'];
            }
        }
        
        for (int i = 0; i < 26; ++i) {
            if (even[i] != 0 || odd[i] != 0)
                return false;
        }
        
        return true;
    }
};