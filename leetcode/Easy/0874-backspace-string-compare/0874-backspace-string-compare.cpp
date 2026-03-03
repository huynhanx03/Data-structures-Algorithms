/*
 Problem: 874. Backspace String Compare
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.3 MB (96.01%)
 Tags: Two Pointers, String, Stack, Simulation
*/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }
    
private:
    string build(const string& str) {
        string result;
        for (char ch : str) {
            if (ch != '#') {
                result.push_back(ch);
            } else if (!result.empty()) {
                result.pop_back();
            }
        }
        return result;
    }
};
