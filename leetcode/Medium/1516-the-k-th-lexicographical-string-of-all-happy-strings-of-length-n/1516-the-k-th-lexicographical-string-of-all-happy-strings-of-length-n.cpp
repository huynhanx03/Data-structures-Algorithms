/*
 Problem: 1516. The k-th Lexicographical String of All Happy Strings of Length n
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 7.7 MB (96.73%)
 Tags: String, Backtracking
*/
class Solution {
public:
    string getHappyString(int n, int k) {
        int totalHappyStrings = 3 * (1 << (n - 1));
        if (k > totalHappyStrings)
            return "";

        string result = "";
        char prev = 0;
        k--;

        for (int i = 0; i < n; ++i) {
            for (char c : {'a', 'b', 'c'}) {
                if (c != prev) {
                    int numSeq = 1 << (n - i - 1);
                    if (k < numSeq) {
                        result += c;
                        prev = c;
                        break;
                    }
                    k -= numSeq;
                }
            }
        }
        
        return result;
    }
};