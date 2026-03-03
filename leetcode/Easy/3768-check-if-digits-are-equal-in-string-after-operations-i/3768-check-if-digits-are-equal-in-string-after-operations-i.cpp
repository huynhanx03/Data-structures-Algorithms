/*
 Problem: 3768. Check If Digits Are Equal in String After Operations I
 Language: cpp
 Runtime: 9 ms (30.79%)
 Memory: 11.6 MB (12.71%)
 Tags: Math, String, Simulation, Combinatorics, Number Theory
*/
class Solution {
public:
    bool hasSameDigits(string s) {
        vector<int> digits;
        digits.reserve(s.size());
        for (char c : s) digits.push_back(c - '0');

        while (digits.size() > 2) {
            vector<int> next;
            next.reserve(digits.size() - 1);
            for (size_t i = 0; i + 1 < digits.size(); ++i) {
                next.push_back((digits[i] + digits[i + 1]) % 10);
            }
            digits.swap(next);
        }

        return digits[0] == digits[1];
    }
};