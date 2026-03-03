/*
 Problem: 17. Letter Combinations of a Phone Number
 Language: cpp
 Runtime: 4 ms (1.31%)
 Memory: 8.1 MB (100.00%)
 Tags: Hash Table, String, Backtracking
*/
class Solution {
public:
    vector<string> ans;

    const char phone[9][4] = {
        {'\0', '\0', '\0', '\0'}, {'a', 'b', 'c', '\0'}, {'d', 'e', 'f', '\0'},
        {'g', 'h', 'i', '\0'},    {'j', 'k', 'l', '\0'}, {'m', 'n', 'o', '\0'},
        {'p', 'q', 'r', 's'},     {'t', 'u', 'v', '\0'}, {'w', 'x', 'y', 'z'},
    };

    void backtracking(string& digits, int index, int sizeD, string res) {
        if (index == sizeD) {
            ans.push_back(res);
            return;
        }

        int num = 3;

        if (digits[index] == '7' || digits[index] == '9')
            num += 1;

        int numDigit = digits[index] - '0' - 1;

        for (int i = 0; i < num; ++i) {
            backtracking(digits, index + 1, sizeD, res + phone[numDigit][i]);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits != "")
            backtracking(digits, 0, digits.size(), "");
        
        return ans;
    }
};