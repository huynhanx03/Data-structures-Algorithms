/*
 Problem: 4178. Vowel-Consonant Score
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 9.1 MB (34.46%)
 Tags: String, Simulation
*/
class Solution {
public:
    int vowelConsonantScore(string s) {
        vector <bool> check(26, 0);
        check['a' - 'a'] = 1;
        check['e' - 'a'] = 1;
        check['i' - 'a'] = 1;
        check['o' - 'a'] = 1;
        check['u' - 'a'] = 1;
        int d1 = 0, d2 = 0;
        for (char x : s) {
            if (!(x >= 'a' && x <= 'z')) continue;
            
            if (check[x - 'a']) ++d1;
            else ++d2;
        }

        if (d2 > 0) return d1 / d2;
        return 0;
    }
};