/*
 Problem: 6. Zigzag Conversion
 Language: cpp
 Runtime: 31 ms (9.35%)
 Memory: 19.6 MB (9.70%)
 Tags: String
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector <vector<char>> rows(numRows, vector<char>());

        int index = 0;
        int value = 1;

        for (const auto& c: s) {
            rows[index].push_back(c);

            index += value;

            if (index >= numRows || index < 0) {
                value = -value;

                index += value * 2;
            }
        }

        string res = "";

        for (const auto row : rows) {
            for (const auto r : row) {
                res += r;
            }
        }

        return res;
    }
};