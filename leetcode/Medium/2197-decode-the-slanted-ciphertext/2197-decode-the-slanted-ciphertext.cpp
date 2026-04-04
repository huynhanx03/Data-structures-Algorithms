/*
 Problem: 2197. Decode the Slanted Ciphertext
 Language: cpp
 Runtime: 19 ms (84.75%)
 Memory: 36.6 MB (90.68%)
 Tags: String, Simulation
*/
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        const int n = encodedText.size();
        const int cols = n / rows;

        string res;
        res.reserve(n);

        for (int start = 0; start < cols; ++start) {
            int i = 0, j = start;
            while (i < rows && j < cols) {
                res += encodedText[i * cols + j];
                ++i;
                ++j;
            }
        }

        while (!res.empty() && res.back() == ' ') {
            res.pop_back();
        }

        return res;
    }
};