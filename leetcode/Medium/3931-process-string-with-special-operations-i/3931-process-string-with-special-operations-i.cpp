/*
 Problem: 3931. Process String with Special Operations I
 Language: cpp
 Runtime: 4 ms (63.20%)
 Memory: 39.8 MB (71.83%)
 Tags: String, Simulation
*/
class Solution {
public:
    string processStr(string s) {
        string result;

        for (const auto& c : s) {
            if ('a' <= c && c <= 'z') {
                result.push_back(c);
            }
            else if (c == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            }
            else if (c == '#') {
                result += result;
            }
            else if (c == '%') {
                reverse(result.begin(), result.end());
            }
        }

        return result;
    }
};