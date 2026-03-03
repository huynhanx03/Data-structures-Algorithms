/*
 Problem: 3799. Unique 3-Digit Even Numbers
 Language: cpp
 Runtime: 12 ms (30.12%)
 Memory: 31 MB (51.59%)
 Tags: Array, Hash Table, Recursion, Enumeration
*/
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
         set<int> uniqueNumbers;

        for (int i = 0; i < digits.size(); ++i) {
            for (int j = 0; j < digits.size(); ++j) {
                for (int k = 0; k < digits.size(); ++k) {
                    if (i != j && j != k && i != k) {
                        int hundreds = digits[i];
                        int tens = digits[j];
                        int ones = digits[k];
                        int number = hundreds * 100 + tens * 10 + ones;

                        if (hundreds != 0 && number % 2 == 0) { 
                            uniqueNumbers.insert(number);
                        }
                    }
                }
            }
        }

        return uniqueNumbers.size();
    }
};