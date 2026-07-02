/*
 Problem: 4313. Password Strength
 Language: cpp
 Runtime: 23 ms (39.25%)
 Memory: 17.6 MB (68.25%)
 Tags: Hash Table, String
*/
class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> seen;
        int ans = 0;

        for (char c : password) {
            if (seen.count(c)) continue;

            seen.insert(c);

            if ('a' <= c && c <= 'z') ans += 1;
            else if ('A' <= c && c <= 'Z') ans += 2;
            else if ('0' <= c && c <= '9') ans += 3;
            else if (c == '!' || c == '@' || c == '#' || c == '$')
                ans += 5;
        }

        return ans;
    }
};