/*
 Problem: 4305. Check Adjacent Digit Differences
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.5 MB (97.54%)
 Tags: String
*/
class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for (int i = 1; i < s.size(); ++i) {
            if (abs((s[i] - '0') - (s[i - 1] - '0')) > 2) return false;
        }
        
        return true;
    }
};