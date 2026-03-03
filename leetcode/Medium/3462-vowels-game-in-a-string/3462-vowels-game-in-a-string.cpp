/*
 Problem: 3462. Vowels Game in a String
 Language: cpp
 Runtime: 3 ms (81.41%)
 Memory: 19 MB (51.26%)
 Tags: Math, String, Brainteaser, Game Theory
*/
class Solution {
public:
    bool doesAliceWin(string s) {
        for (const auto& c: s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                return true;          
        }      

        return false;
    }
};