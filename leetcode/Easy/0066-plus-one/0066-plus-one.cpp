/*
 Problem: 66. Plus One
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 10.6 MB (99.95%)
 Tags: Array, Math
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        int tmp = 1;

        for (int i = n - 1; i >= 0; --i) {
            digits[i] += tmp;

            if (digits[i] > 9) {
                tmp = 1;
                digits[i] = 0;
            } else {
                tmp = 0;
                break;
            }
        }

        if (tmp) {
            digits[0] = 1;
            digits.push_back(0);
        }
        
        return digits;
    }
};