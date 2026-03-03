/*
 Problem: 273. Integer to English Words
 Language: cpp
 Runtime: 3 ms (49.33%)
 Memory: 12.1 MB (18.30%)
 Tags: Math, String, Recursion
*/
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        return intToString(num).substr(1);
    }

private:
    vector<string> lessThan20 = {
        "",        "One",     "Two",       "Three",    "Four",
        "Five",    "Six",     "Seven",     "Eight",    "Nine",
        "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"",      "",      "Twenty",  "Thirty", "Forty",
                           "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};

    string intToString(int num) {
        if (num == 0)
            return "";
        if (num < 20)
            return " " + lessThan20[num];
        if (num < 100)
            return " " + tens[num / 10] + intToString(num % 10);
        if (num < 1000)
            return " " + lessThan20[num / 100] + " Hundred" +
                   intToString(num % 100);
        for (int i = 0; i < thousands.size(); ++i) {
            if (num < pow(1000, i + 1))
                return intToString(num / pow(1000, i)) + " " + thousands[i] +
                       intToString(num % (int)pow(1000, i));
        }
        return "";
    }
};