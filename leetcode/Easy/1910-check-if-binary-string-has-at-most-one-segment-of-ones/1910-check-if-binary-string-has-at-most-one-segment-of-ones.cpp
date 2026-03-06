/*
 Problem: 1910. Check if Binary String Has at Most One Segment of Ones
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.2 MB (77.26%)
 Tags: String
*/
class Solution {
public:
    bool checkOnesSegment(string s) {
        bool has = false;

        for (const auto& c : s) {
            if (c == '0') {
                has = true;
            } 
            else if (has) {
                return false;
            }
        }

        return true;
    }
};