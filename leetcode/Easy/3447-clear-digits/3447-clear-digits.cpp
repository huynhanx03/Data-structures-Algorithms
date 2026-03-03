/*
 Problem: 3447. Clear Digits
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.4 MB (71.79%)
 Tags: String, Stack, Simulation
*/
class Solution {
public:
    string clearDigits(string s) {
        while (true) {
            bool found_digit = false;
            for (int i = 0; i < s.size(); ++i) {
                if (isdigit(s[i])) {
                    found_digit = true;
                    for (int j = i - 1; j >= 0; --j) {
                        if (!isdigit(s[j])) {
                            s.erase(j, 1);
                            break;
                        }
                    }
                    s.erase(i - 1, 1);
                    break;
                }
            }
            if (!found_digit)
                break;
        }
        return s;
    }
};